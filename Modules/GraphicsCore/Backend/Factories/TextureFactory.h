// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once
#ifndef _EDK_GRAPHICS_CORE_TEXTURE_FACTORY_H
#define _EDK_GRAPHICS_CORE_TEXTURE_FACTORY_H

#include "GraphicsCore/Backend/Objects/Texture.h"

namespace EDK
{
	namespace Graphics
	{
		/**
		 * Texture Factory for the EDK.
		 */
		class TextureFactory : public GObject {
		public:
			/**
			 * Default constructor.
			 */
			TextureFactory() {}

			/**
			 * Default destructor.
			 */
			virtual ~TextureFactory() {}

			/**
			 * Create a raw texture using the extent.
			 *
			 * @param extent: The extent of the texture.
			 * @param format: The texture data format.
			 * @return: Created texture object pointer.
			 */
			virtual Texture* CreateRawTexture(TextureExtent extent, Format format) { return nullptr; }

			/**
			 * Destroy a created texture.
			 *
			 * @param pTexture: The texture to be destroyed.
			 */
			virtual void DestroyTexture(Texture* pTexture) {}
		};
	}
}

#endif // !_EDK_GRAPHICS_CORE_TEXTURE_FACTORY_H
