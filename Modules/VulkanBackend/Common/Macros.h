// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once
#ifndef _EDK_VULKAN_BACKEND_MACROS_H
#define _EDK_VULKAN_BACKEND_MACROS_H

#include "ErrorHandler/Logger.h"

/**
 * Vulkan Assert macro.
 * This checks if the return of an expression is equal to VK_SUCCESS.
 *
 * @param exp: The expression.
 * @msg: The message to be logged if failed.
 */
#define EDK_VK_ASSERT(exp, msg)	if (exp != VK_SUCCESS)	::EDK::ErrorHandler::Logger::LogError(TEXT(msg))

#endif // !_EDK_VULKAN_BACKEND_MACROS_H
