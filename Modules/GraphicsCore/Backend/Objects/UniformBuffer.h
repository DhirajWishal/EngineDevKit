// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once
#ifndef _EDK_GRAPHCIS_CORE_UNIFORM_BUFFER_H
#define _EDK_GRAPHCIS_CORE_UNIFORM_BUFFER_H

#include "Buffer.h"

namespace EDK
{
	namespace Graphics
	{
		/**
		 * Uniform Type enum.
		 */
		enum class UniformType : UI32 {
			UNIFORM_Type_UNIFORM_BUFFER,
		};

		/**
		 * Uniform Buffer for the EDK.
		 * This object is used to submit uniform data to the shaders.
		 */
		class UniformBuffer : public Buffer {
		public:
			/**
			 * Default constructor.
			 */
			UniformBuffer() {}

			/**
			 * Default destructor.
			 */
			virtual ~UniformBuffer() {}

			/**
			 * Set the binding of the buffer in the shader.
			 *
			 * @param binding: The shader binding index.
			 */
			void SetBinding(UI32 binding) { this->binding = binding; }

			/**
			 * Get the shader binding index.
			 *
			 * @return: Unsigned 32 bit integer.
			 */
			UI32 GetBinding() const { return binding; }

			/**
			 * Set the type of the uniform buffer.
			 *
			 * @param type: The type to be set.
			 */
			void SetType(UniformType type) { this->type = type; }

			/**
			 * Get the uniform buffer type.
			 *
			 * @return: EDK::GraphcisCore::UniformType enum.
			 */
			UniformType GetType() const { return type; }

		protected:
			UI32 binding = 0;	// Binding of the buffer.
			UniformType type = UniformType::UNIFORM_Type_UNIFORM_BUFFER;	// The uniform buffer type.
		};
	}
}

#endif // !_EDK_GRAPHCIS_CORE_UNIFORM_BUFFER_H
