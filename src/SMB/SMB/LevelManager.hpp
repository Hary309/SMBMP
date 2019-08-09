/** @file LevelManager.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

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
			call Offsets::LevelManager_loadLevel
		}
	}

	static LevelManager* get()
	{
		return *(LevelManager**)(Offsets::LevelManager_ptr);
	}
};
