// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#include "VulkanBackend/VulkanBackendInstance.h"
#include "Core/Types/Utilities.h"
#include "VulkanBackend/Common/VulkanDevice.h"

#include <iostream>

namespace EDK
{
	namespace Graphics
	{
		namespace VulkanBackend
		{
			/**
			 * Error callback function for GLFW.
			 *
			 * @param errorCode: The error code.
			 * @param pDescription: The error description.
			 */
			static void GLFWErrorCallback(I32 errorCode, const char* pDescription)
			{
				ErrorHandler::Logger::LogError(WString(TEXT("GLFW -> ") + StringToWString(pDescription)).c_str());
			}

			void VulkanBackendInstance::Initialize(BackendInitInfo intiInfo)
			{
				// Initialize the GLFW instance.
				SetupGLFW();

				// Initialize the instance.
				InitializeInstance();

				// Initialize the debugger if validation is enabled.
				if (initInfo.enableValidation)
				{
					validationLayers.push_back("VK_LAYER_KHRONOS_validation");
					InitializeDebugger();
				}
			}

			void VulkanBackendInstance::Terminate()
			{
				// Initialize the debugger if validation is enabled.
				if (initInfo.enableValidation)
					TeminateDebugger();

				// Terminate the instance.
				TerminateInstance();
			}

			std::shared_ptr<GDevice> VulkanBackendInstance::CreateDeviceObject(DeviceInitInfo initInfo)
			{
				// Allocate the device.
				std::shared_ptr<VulkanDevice> pDevice = std::make_shared<VulkanDevice>(VulkanDevice());

				// Set the parent instance.
				pDevice->SetParentInstance(this);

				// Initialize the device.
				initInfo.enableRayTracing = this->initInfo.enableRayTracing;
				initInfo.enableValidation = this->initInfo.enableValidation;
				pDevice->Initialize(initInfo);

				// Return the casted device pointer.
				return std::move(pDevice);
			}

			void VulkanBackendInstance::DestroyDevice(std::shared_ptr<GDevice> pDevice)
			{
				// Terminate the device.
				pDevice->Terminate();

				// Deallocate the Vulkan Device.
				delete pDevice.release()->Inherit<VulkanDevice>();
			}

			/**
			 * Check if the requested validation layers are supported.
			 *
			 * @param layers: The validation layers to be checked.
			 * @return: Boolean value.
			 */
			inline bool CheckValidationLayerSupport(std::vector<const char*> layers)
			{
				UI32 layerCount = 0;
				vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

				std::vector<VkLayerProperties> availableLayers(layerCount);
				vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

				// Iterate through the layers to check if all the layers are supported.
				for (const char* layerName : layers)
				{
					bool layerFound = false;

					for (const VkLayerProperties& layerProperties : availableLayers)
					{
						if (strcmp(layerName, layerProperties.layerName) == 0)
						{
							layerFound = true;
							break;
						}
					}

					// Return false an unsupported layer was found.
					if (!layerFound)
						return false;
				}

				return true;
			}

			/**
			 * Get the requires instance extensions from GLFW.
			 *
			 * @return: std::vector<const char*> containing the required extensions.
			 */
			EDK_FORCEINLINE std::vector<const char*> GetRequiredInstanceExtensions()
			{
				UI32 glfwExtentionCount = 0;
				const char** glfwExtentions = nullptr;
				glfwExtentions = glfwGetRequiredInstanceExtensions(&glfwExtentionCount);
				std::vector<const char*> extentions(glfwExtentions, glfwExtentions + glfwExtentionCount);

				//if (pushDescriptorsSupported)
				//	extentions.push_back(VK_KHR_PUSH_DESCRIPTOR_EXTENSION_NAME);
				//
				//if (checkpointsSupported)
				//	extentions.push_back(VK_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_EXTENSION_NAME);
				//
				//if (meshShadingSupported)
				//	extentions.push_back(VK_NV_MESH_SHADER_EXTENSION_NAME);

				extentions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

				//extentions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);

				return extentions;
			}

			/**
			 * Debug Callback function for Vulkan.
			 * This function is used to return debug information provided by Vulkan.
			 *
			 * @param messageSeverity: The severity of the message.
			 * @param messageType: The type of the message.
			 * @param pCallbackData: The callback data.
			 * @param pUserData: The user data that triggered the messenger.
			 * @return: VkBool32 value.
			 */
			static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
				VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
				VkDebugUtilsMessageTypeFlagsEXT messageType,
				const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
				void* pUserData)
			{
				WString myMessageStatement = TEXT("Vulkan Validation Layer ");
				WString myMessagePreStatement = TEXT(": ");

				if (messageType == VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT)
					myMessagePreStatement = TEXT("(General): ");
				else if (messageType == VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT)
					myMessagePreStatement = TEXT("(Validation): ");
				else if (messageType == VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT)
					myMessagePreStatement = TEXT("(Performance): ");

				switch (messageSeverity) {
				case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
					ErrorHandler::Logger::LogDebug(WString(TEXT("") + (myMessageStatement + myMessagePreStatement + StringToWString(pCallbackData->pMessage))).c_str());
					break;
				case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
					ErrorHandler::Logger::LogInfo(WString(TEXT("") + (myMessageStatement + myMessagePreStatement + StringToWString(pCallbackData->pMessage))).c_str());
					break;
				case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
					ErrorHandler::Logger::LogWarn(WString(TEXT("") + (myMessageStatement + myMessagePreStatement + StringToWString(pCallbackData->pMessage))).c_str());
					break;
				case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
					ErrorHandler::Logger::LogError(WString(TEXT("") + (myMessageStatement + myMessagePreStatement + StringToWString(pCallbackData->pMessage))).c_str());
					break;
				default:
					std::wcerr << myMessageStatement << myMessagePreStatement << StringToWString(pCallbackData->pMessage) << std::endl;
					break;
				}

				return VK_FALSE;
			}

			/**
			 * Create a new VkDebugUtilsMessengerCreateInfoEXT object.
			 *
			 * @return: The newly created VkDebugUtilsMessengerCreateInfoEXT object.
			 */
			EDK_FORCEINLINE VkDebugUtilsMessengerCreateInfoEXT CreateDebugMessengerCreateInfo()
			{
				VkDebugUtilsMessengerCreateInfoEXT createInfo = {};
				createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
				createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT
					| VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT
					| VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
				createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT
					| VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT
					| VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
				createInfo.pfnUserCallback = DebugCallback;

				createInfo.pNext = VK_NULL_HANDLE;
				createInfo.pUserData = VK_NULL_HANDLE;
				createInfo.flags = VK_NULL_HANDLE;

				return createInfo;
			}

			void VulkanBackendInstance::SetupGLFW()
			{
				// Set the error callback.
				glfwSetErrorCallback(GLFWErrorCallback);

				// Initialize GLFW.
				glfwInit();

				// Setup hints.
				{
					glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
					glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
					glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
					glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
					glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
				}
			}

			void VulkanBackendInstance::InitializeInstance()
			{
				// Check if the validation layers are supported.
				if (initInfo.enableValidation && !CheckValidationLayerSupport(validationLayers))
					ErrorHandler::Logger::LogError(TEXT("Requested validation layers are not available!"));

				// Application info.
				VkApplicationInfo appInfo = {};
				appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
				appInfo.pApplicationName = "EDK";
				appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
				appInfo.pEngineName = "EDK";
				appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
				appInfo.apiVersion = VK_API_VERSION_1_2;

				// Instance create info.
				VkInstanceCreateInfo createInfo = {};
				createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
				createInfo.pApplicationInfo = &appInfo;

				// Get and insert the required instance extensions.
				auto requiredExtentions = GetRequiredInstanceExtensions();
				instanceExtensions.insert(instanceExtensions.end(), requiredExtentions.begin(), requiredExtentions.end());
				createInfo.enabledExtensionCount = static_cast<UI32>(instanceExtensions.size());
				createInfo.ppEnabledExtensionNames = instanceExtensions.data();

				// Initialize debugger.
				VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo = {};
				if (initInfo.enableValidation)
				{
					createInfo.enabledLayerCount = static_cast<UI32>(validationLayers.size());
					createInfo.ppEnabledLayerNames = validationLayers.data();

					debugCreateInfo = CreateDebugMessengerCreateInfo();
					createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
				}
				else
				{
					createInfo.enabledLayerCount = 0;
					createInfo.pNext = nullptr;
				}

				// Create the instance handle.
				EDK_VK_ASSERT(vkCreateInstance(&createInfo, nullptr, &vInstance), "Failed to create instance!");
			}

			void VulkanBackendInstance::TerminateInstance()
			{
				vkDestroyInstance(GetInstance(), nullptr);
			}

			void VulkanBackendInstance::InitializeDebugger()
			{
				VkDebugUtilsMessengerCreateInfoEXT createInfo = CreateDebugMessengerCreateInfo();

				auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(GetInstance(), "vkCreateDebugUtilsMessengerEXT");

				// Create the debug messenger handle.
				EDK_VK_ASSERT(func(vInstance, &createInfo, nullptr, &vDebugMessenger), "Failed to create the debug messenger!");
			}

			void VulkanBackendInstance::TeminateDebugger()
			{
				auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(GetInstance(), "vkDestroyDebugUtilsMessengerEXT");

				if (func != nullptr)
					func(GetInstance(), vDebugMessenger, nullptr);
			}
		}
	}
}