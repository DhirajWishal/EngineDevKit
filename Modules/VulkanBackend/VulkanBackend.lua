-- Copyright 2020 Dhiraj Wishal
-- SPDX-License-Identifier: Apache-2.0

---------- Vulkan Backend project description ----------

project "VulkanBackend"
	kind "StaticLib"
	language "C++"
	systemversion "latest"
	cppdialect "C++17"
	staticruntime "On"

	defines {
		"EDK_INTERNAL",
		"GLFW_INCLUDE_VULKAN"
	}

	targetdir "$(SolutionDir)Builds/Binaries/$(Configuration)-$(Platform)"
	objdir "$(SolutionDir)Builds/Intermediate/$(Configuration)-$(Platform)/$(ProjectName)"

	files {
		"**.txt",
		"**.cpp",
		"**.h",
		"**.lua",
		"**.txt",
		"**.md",
	}

	includedirs {
		"$(SolutionDir)Modules/",
		"%{IncludeDir.Vulkan}",
		"%{IncludeDir.GLFW}",
	}

	libdirs {
		"%{IncludeLib.Vulkan}",
		"%{IncludeLib.GLFW}",
	}

	links { 
		"GraphicsCore",
		"vulkan-1",
		"glfw3dll",
	}

	filter "system:windows"
		defines {
			"EDK_PLATFORM_WINDOWS",
		}

	filter "system:linux"
		defines {
			"EDK_PLATFORM_LINUX",
		}

	filter "system:macosx"
		defines {
			"EDK_PLATFORM_MAC",
		}