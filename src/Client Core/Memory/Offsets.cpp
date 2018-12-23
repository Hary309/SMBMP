#include "Offsets.hpp"

#include <Windows.h>
#include <cstdio>

unsigned Offsets::baseAddr = 0;

void Offsets::init()
{
	baseAddr = (unsigned)GetModuleHandle(0) - 0x400000;

	printf("Offsets initialized! Base address = %X or %X\n", baseAddr, getAddr(0x00481920) - 0x00481920);
}

unsigned Offsets::getAddr(unsigned addr)
{
	return baseAddr + addr;
}

unsigned Offsets::getBaseAddr()
{
	return baseAddr;
}

unsigned Offsets::solveAddr(unsigned addr)
{
	return addr - baseAddr;
}
