#pragma once

#include <cstdio>

class MemMgr
{
public:
	static void UnprotectMemory(uintptr_t addr, size_t size);

	static void JmpHook(uintptr_t addr, uintptr_t addrTo);
};
