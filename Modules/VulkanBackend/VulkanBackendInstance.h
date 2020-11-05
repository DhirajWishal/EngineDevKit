// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once
#ifndef _EDK_VULKAN_BACKEND_INSTANCE_H
#define _EDK_VULKAN_BACKEND_INSTANCE_H

#include "GraphicsCore/Backend/BackendInstance.h"
#include "Common/VulkanDevice.h"

namespace EDK
{
	namespace Graphics
	{
		namespace VulkanBackend
		{
			/**
			 * Vulkan Backend Instance object.
			 * This contains all the functionality of the Vulkan Instance.
			 */
			class VulkanBackendInstance : public BackendInstance {
			public:
				/**
				 * Default constructor.
				 */
				VulkanBackendInstance() {}

				/**
				 * Default destructor.
				 */
				~VulkanBackendInstance() {}

				/**
				 * Initialize the backend instance.
				 */
				virtual void Initialize(BackendInitInfo intiInfo) override final;

				/**
				 * Terminate the backend instance.
				 */
				virtual void Terminate() override final;

			public:
				/**
				 * Create a new backend device object.
				 * Since each and every graphics window contains a device attached to it, to create multiple displays
				 * and render object to them, different devices are required.
				 *
				 * @param initInfo: Graphics Device Init Info structure.
				 * @return: Pointer to the created device object.
				 */
				virtual std::unique_ptr<GDevice> CreateDeviceObject(DeviceInitInfo initInfo) override final;

				/**
				 * Destroy a created device object.
				 *
				 * @param pDevice: The device object pointer.
				 */
				virtual void DestroyDevice(std::unique_ptr<GDevice> pDevice) override final;

			public:
				/**
				 * Get the Vulkan Instance.
				 *
				 * @return: VkInstance handle.
				 */
				EDK_FORCEINLINE VkInstance GetInstance() const { return vInstance; }

				/**
				 * Get the Vulkan Debug Messenger.
				 *
				 * @return: VkDebugUtilsMessengerEXT handle.
				 */
				EDK_FORCEINLINE VkDebugUtilsMessengerEXT GetDebugMessenger() const { return vDebugMessenger; }

				/**
				 * Get the validation layers used by the instance.
				 *
				 * @param: The vector containing the validation layers.
				 */
				EDK_FORCEINLINE const std::vector<const char*>& GetValidationLayers() const { return this->validationLayers; }

			private:
				/**
				 * Setup the GLFW instance.
				 */
				void SetupGLFW();

				/**
				 * Initialize the Vulkan Instance.
				 */
				void InitializeInstance();

				/**
				 * Terminate the Vulkan Instance.
				 */
				void TerminateInstance();

				/**
				 * Initialize the Vulkan Debugger.
				 */
				void InitializeDebugger();

				/**
				 * Terminate the Vulkan Debugger.
				 */
				void TeminateDebugger();

			public:
				std::vector<const char*> validationLayers;	// Validation layers.
				std::vector<const char*> instanceExtensions;	// Instance extensions.

				VkInstance vInstance = VK_NULL_HANDLE;	// Vulkan instance handle.
				VkDebugUtilsMessengerEXT vDebugMessenger = VK_NULL_HANDLE;	// Vulkan debug messenger handle.
			};
		}
	}
}

#endif // !_EDK_VULKAN_BACKEND_INSTANCE_H
