// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#include "Memory/AutomatedMemoryManager.h"
#include "Memory/StaticAllocator.h"

namespace EDK
{
	namespace Memory
	{
		AutomatedMemoryManager::AutomatedMemoryManager()
		{
		}

		AutomatedMemoryManager::~AutomatedMemoryManager()
		{
			for (auto _address : memoryMap)
			{
#ifdef EDK_DEBUG
				printf("Deleting 0x%p from the automated memory manager.\n", _address.second);

#endif // EDK_DEBUG
				StaticAllocator<BYTE>::RawDeallocate(Cast<BYTE*>(_address.second), 0);
			}
		}

		AutomatedMemoryManager AutomatedMemoryManager::instance;

		UI64 AutomatedMemoryManager::GetAllocationCount()
		{
			return instance.memoryMap.size();
		}

		void AutomatedMemoryManager::Deallocate(void* location, UI64 size, UI64 offset, UI64 alignment)
		{
			StaticAllocator<BYTE>::RawDeallocate(Cast<BYTE*>(location), size, alignment, offset);
			instance.memoryMap.erase((UI64)location);
		}
	}
}