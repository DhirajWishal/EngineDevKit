// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once
#ifndef _EDK_CORE_MEMORY_FUNCTIONS_H
#define _EDK_CORE_MEMORY_FUNCTIONS_H

#include "Core/Types/DataTypes.h"

namespace EDK
{
	namespace Memory
	{
		/**
		 * Move data from one location to another.
		 *
		 * @param destination: Destination address.
		 * @param source: SourceAddress
		 * @param byteSize: Number of bytes to be moved.
		 */
		void MoveData(void* destination, const void* source, UI64 byteSize);

		/**
		 * Copy data from one location to another.
		 *
		 * @param destination: Destination address.
		 * @param source: SourceAddress
		 * @param byteSize: Number of bytes to be copied.
		 */
		void CopyData(void* destination, const void* source, UI64 byteSize);

		/**
		 * Set data to a whole block of memory.
		 *
		 * @param destination: Destination address.
		 * @param byteValue: The value to be set with.
		 * @param byteSize: Number of bytes to be filled.
		 */
		void SetData(void* destination, BYTE byteValue, UI64 byteSize);
	}
}

#endif // !_EDK_CORE_MEMORY_FUNCTIONS_H
