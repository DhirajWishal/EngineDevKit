// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once
#ifndef _EDK_GRAPHICS_CORE_STAGGING_BUFFER_H
#define _EDK_GRAPHICS_CORE_STAGGING_BUFFER_H

#include "Buffer.h"

namespace EDK
{
	namespace Graphics
	{
		/**
		 * Stagging Buffer for the EDK.
		 * This buffer is used much like one-time and is used to transfer data from one to another. Mostly used when
		 * trasfering texture data from the local image to the GPU address space.
		 */
		class StaggingBuffer : public Buffer {
		public:
			/**
			 * Default constructor.
			 */
			StaggingBuffer() {}

			/**
			 * Default destructor.
			 */
			virtual ~StaggingBuffer() {}
		};
	}
}

#endif // !_EDK_GRAPHICS_CORE_STAGGING_BUFFER_H
