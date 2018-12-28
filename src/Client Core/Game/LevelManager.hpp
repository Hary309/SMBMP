#pragma once

#include <string>

#include "Memory/Offsets.hpp"

class LevelManager
{
public:
	void loadLevel(int chapter, int level)
	{
		char name[32] = { 0 };
		sprintf_s(name, "%d-%d", chapter, level);
		loadLevel(name);
	}

	void loadLevel(const char* name)
	{
		uintptr_t functionAddr = Offsets::getAddr(0x000AAB80);

		auto nameAddr = &name;

		__asm
		{
			push nameAddr
			mov ecx, this
			call functionAddr
		}
	}

	static LevelManager* get()
	{
		return *(LevelManager**)(Offsets::getAddr(0x0030A46C));
	}
};
