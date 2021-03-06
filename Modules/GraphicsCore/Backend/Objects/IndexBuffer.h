// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once
#ifndef _EDK_GRAPHICS_CORE_INDEX_BUFFER_H
#define _EDK_GRAPHICS_CORE_INDEX_BUFFER_H

#include "Buffer.h"

namespace EDK
{
	namespace Graphics
	{
		/**
		 * Index Buffer object for the EDK.
		 * This buffer is used to store index data.
		 */
		class IndexBuffer : public Buffer {
		public:
			/**
			 * Default constructor.
			 */
			IndexBuffer() {}

			/**
			 * Default destructor.
			 */
			virtual ~IndexBuffer() {}

			/**
			 * Set the index size of the index buffer.
			 *
			 * @param indexSize: The size of the index in bytes.
			 */
			void SetIndexSize(UI8 indexSize) { this->indexSize = indexSize; }

			/**
			 * Get the index size in bytes.
			 *
			 * @return: Unsigned 8 bit integer of the size.
			 */
			UI8 GetIndexSize() const { return indexSize; }

		protected:
			UI8 indexSize = 0;	// The index size in bytes.
		};
	}
}

#endif // !_EDK_GRAPHICS_CORE_INDEX_BUFFER_H
