#include "MemMgr.h"

#include <windows.h>

void MemMgr::UnprotectMemory(uintptr_t addr, size_t size)
{
	DWORD temp;
	VirtualProtect((void*)addr, size, PAGE_EXECUTE_READWRITE, &temp);
}

void MemMgr::JmpHook(uintptr_t addr, uintptr_t addrTo)
{
	UnprotectMemory(addr, 5);

	*(unsigned char*)(addr) = 0xE9;
	*(unsigned*)(addr + 1) = addrTo - (addr + 5);
}
