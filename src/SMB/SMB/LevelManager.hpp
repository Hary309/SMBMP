#pragma once

#include "SMB.hpp"

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
		auto nameAddr = &name;

		__asm
		{
			push nameAddr
			mov ecx, this
			call GameOffsets::LevelManager_loadLevel
		}
	}

	static LevelManager* get()
	{
		return *(LevelManager**)(GameOffsets::LevelManager_ptr);
	}
};
