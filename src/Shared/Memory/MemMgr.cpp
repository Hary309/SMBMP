#include "MemMgr.hpp"

#include <windows.h>

void MemMgr::UnprotectMemory(uintptr_t addr, size_t size)
{
	DWORD temp;
	VirtualProtect((void*)addr, size, PAGE_EXECUTE_READWRITE, &temp);
}

void MemMgr::JmpHook(uintptr_t addr, uintptr_t addrTo)
{
	UnprotectMemory(addr, 5);

	*(uint8_t*)(addr) = 0xE9;
	*(uintptr_t*)(addr + 1) = addrTo - (addr + 5);
}

void MemMgr::MemSet(uintptr_t addr, uint8_t value, size_t size)
{
	UnprotectMemory(addr, size);
	memset((void*)addr, value, size);
}
