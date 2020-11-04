// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once
#ifndef _EDK_GRAPHICS_CORE_TEXTURE_SAMPLER_H
#define _EDK_GRAPHICS_CORE_TEXTURE_SAMPLER_H

#include "Texture.h"

namespace EDK
{
	namespace GraphicsCore
	{
		/**
		 * Texture Sampler for the EDK.
		 * This object is used to render a texture.
		 */
		class TextureSampler : public GObject {
		public:
			/**
			 * Default constructor.
			 */
			TextureSampler() {}

			/**
			 * Default destructor.
			 */
			virtual ~TextureSampler() {}
		};
	}
}

#endif // !_EDK_GRAPHICS_CORE_TEXTURE_SAMPLER_H
