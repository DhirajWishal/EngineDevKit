// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#include "ErrorHandler/Logger.h"
#include "Maths/Vector/Vector3.h"
#include "Memory/StaticAllocator.h"

#include "Maths/Matrix/Matrix22.h"

int main()
{
	EDK::Logger::LogInfo(TEXT("EDK Core Test!"));

	EDK::Vector3 vector = { 0.0f, 2.0f, 1.0f };
	auto v2 = vector + vector;

	EDK::Matrix22 mat = EDK::Matrix22::Identity;

	auto pData = EDK::StaticAllocator<int>::Allocate();
	EDK::StaticAllocator<int>::Deallocate(pData);
}