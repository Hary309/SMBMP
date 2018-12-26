#pragma once

#include <stdint.h>

class Offsets
{
private:
	static uintptr_t baseAddr;

public:
	static void init();

	static uintptr_t getAddr(uintptr_t addr);
	static uintptr_t solveAddr(uintptr_t addr);

	static uintptr_t getBaseAddr();
};
