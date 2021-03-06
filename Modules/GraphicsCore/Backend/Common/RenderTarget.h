// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once
#ifndef _EDK_GRAPHICS_RENDER_TARGET_H
#define _EDK_GRAPHICS_RENDER_TARGET_H

#include "GObject.h"

namespace EDK
{
	namespace Graphics
	{
		/**
		 * Render Target for the EDK Graphics module.
		 */
		class RenderTarget : public GObject {
		public:
			/**
			 * Default constructor.
			 */
			RenderTarget() {}

			/**
			 * Default destructor.
			 */
			virtual ~RenderTarget() {}

			/**
			 * Initialize the render target.
			 */
			virtual void Initialize() {}

			/**
			 * Terminat the render target.
			 */
			virtual void Terminate() {}
		};
	}
}

#endif // !_EDK_GRAPHICS_RENDER_TARGET_H
