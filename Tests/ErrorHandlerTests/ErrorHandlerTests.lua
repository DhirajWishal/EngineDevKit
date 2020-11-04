-- Copyright 2020 Dhiraj Wishal
-- SPDX-License-Identifier: Apache-2.0

---------- Error Handler Tests project description ----------

project "ErrorHandlerTests"
	kind "ConsoleApp"
	cppdialect "C++17"
	language "C++"

	targetdir "$(SolutionDir)Builds/Tests/Binaries/$(Configuration)-$(Platform)/$(ProjectName)"
	objdir "$(SolutionDir)Builds/Tests/Intermediate/$(Configuration)-$(Platform)/$(ProjectName)"

	files {
		"**.txt",
		"**.cpp",
		"**.h",
		"**.lua"
	}

	includedirs {
		"$(SolutionDir)Modules/",
	}

	links {
		"ErrorHandler"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines {
			"EDK_PLATFORM_WINDOWS"
		}