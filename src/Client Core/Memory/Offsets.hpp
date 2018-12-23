#pragma once

class Offsets
{
private:
	static unsigned baseAddr;

public:
	static void init();

	static unsigned getAddr(unsigned addr);
	static unsigned solveAddr(unsigned addr);

	static unsigned getBaseAddr();
};
