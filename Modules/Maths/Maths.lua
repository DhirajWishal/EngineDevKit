-- Copyright 2020 Dhiraj Wishal
-- SPDX-License-Identifier: Apache-2.0

---------- Maths project description ----------

project "Maths"
	kind "StaticLib"
	language "C++"
	systemversion "latest"
	cppdialect "C++17"
	staticruntime "On"

	defines {
		"EDK_INTERNAL"
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
	}

	libdirs {
	}

	links { 
		"ErrorHandler",
		"Memory",
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