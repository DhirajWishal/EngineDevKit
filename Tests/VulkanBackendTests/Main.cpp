// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#include "VulkanBackend/VulkanBackendInstance.h"
using namespace EDK::Graphics;
using namespace EDK::Graphics::VulkanBackend;

/** CONCEPT
 * Create a file named *.das (EDK Asset Serialization) which stores all the vertex data in binary.
 * This way it is easy to stream data directly to the GPU.
 *
 * Data are stored in the following format:
 * 1) Vertex data are stored.
 * 1.1) An unsigned 64 bit integer stating the number of bytes to copy.
 * 1.2) The vertex size.
 * 1.3) The vertex data.
 *
 * 2) Index data are stored.
 * 2.1) An unsigned 64 bit integer stating the number of bytes to copy.
 * 2.2) The index size.
 * 2.3) The index data.
 *
 * 3) Texture data are stored.
 * 3.1) Number (8 bit integer) of textures that are stored.
 * 3.2) 3, 32 bit, semicolon (;) separated integers representing the width, height and depth of the texture.
 * 3.3) 5, 8 bit integers containing format information.
 * 3.4) Texture data.
 * 3.5) Repeat 3.2) for a total count of 3.1).
 *
 * 4) Material  data are stored.
 * 4.1) Number (8 bit integer) containing the number of materials stored.
 * 4.2) Number of bytes to copy.
 * 4.3) The material data.
 * 4.4) Repeat 4.2) for a total count of 4.1).
 */

int main()
{
	VulkanBackendInstance vBackendInstance = {};
	vBackendInstance.Initialize(BackendInitInfo());

	DeviceInitInfo initInfo = {};
	initInfo.enableRayTracing = false;
	auto pDevice = vBackendInstance.CreateDeviceObject(initInfo)->Inherit<VulkanDevice>();
	auto pDevice2 = vBackendInstance.CreateDeviceObject(initInfo);

	int count = 1000;
	while (count--)
	{
		pDevice->BeginFrame();
		pDevice->EndFrame();

		pDevice2->BeginFrame();
		pDevice2->EndFrame();
	}

	vBackendInstance.DestroyDevice(std::unique_ptr<GDevice>(pDevice));
	vBackendInstance.DestroyDevice(std::move(pDevice2));

	vBackendInstance.Terminate();
}