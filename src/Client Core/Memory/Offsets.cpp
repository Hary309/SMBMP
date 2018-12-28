#include "Offsets.hpp"

#include <Windows.h>
#include <cstdio>

uintptr_t Offsets::baseAddr = 0;

void Offsets::init()
{
	baseAddr = (uintptr_t)GetModuleHandle(0);

	printf("Offsets initialized! Base address = %X or %X\n", baseAddr, getAddr(0x00481920) - 0x00481920);
}

uintptr_t Offsets::getAddr(uintptr_t addr)
{
	return baseAddr + addr;
}

uintptr_t Offsets::getBaseAddr()
{
	return baseAddr;
}
