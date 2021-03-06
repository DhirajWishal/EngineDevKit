// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once
#ifndef _EDK_CORE_ERROR_LOGGER_H
#define _EDK_CORE_ERROR_LOGGER_H

#include "Core/Types/DataTypes.h"

namespace EDK
{
	namespace ErrorHandler
	{
		/**
		 *  The logger is a namespace which contains functions which allows the user to log messages to the console.
		 */
		namespace Logger
		{
			/**
			 * Log basic information to the console.
			 * Color: Green.
			 *
			* @param message: The message to be logged.
			 */
			void LogInfo(const wchar_t* message);

			/**
			 * Log a warning message to the console.
			 * Color: Yellow.
			 *
			* @param message: The message to be logged.
			 */
			void LogWarn(const wchar_t* message);

			/**
			 * Log an error message to the console.
			 * Color: Red.
			 *
			* @param message: The message to be logged.
			 */
			void LogError(const wchar_t* message);

			/**
			 * Log a fatal error message to the console.
			 * Color: Red + underlined.
			 *
			* @param message: The message to be logged.
			* @param file: The file the error had occurred.
			* @param line: The line of the error.
			 */
			void LogFatal(const wchar_t* message, const wchar_t* file, UI32 line);

			/**
			 * Log a debug information to the console.
			 * Color: Blue.
			 *
			* @param message: The message to be logged.
			 */
			void LogDebug(const wchar_t* message);
		}
	}
}

#endif // !_DYNAMIK_CORE_ERROR_LOGGER_H