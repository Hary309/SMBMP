#pragma once

#include <stdint.h>

class MemMgr
{
public:
	static void UnprotectMemory(uintptr_t addr, size_t size);

	static void JmpHook(uintptr_t addr, uintptr_t addrTo);

	static void MemSet(uintptr_t addr, uint8_t value, size_t size);
};
