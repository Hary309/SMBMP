#pragma once

#include "SMB.hpp"

#include <SMB/Offsets.hpp>

struct Characters
{
	enum class Type
	{
		MeatBoy8Bit = 1,
		MeatBoy4Color = 2,
		MeatBoy4Bit = 3,
		DrFetus = 4,
		Brownie = 5,
		BandageGirl = 6,
		MeatNinja = 7,
		Naija = 10,
		CommanderVideo = 11,
		Runman = 12,
		GooBall = 13,
		MrMinecraft = 14,
		FlyWrench = 16,
		Jill = 17,
		VVVVVV = 18,
		TofuBoy = 19,
		Machinarium = 20,
		TheKid = 21,
		HeadCrab = 22,
		Ogmo = 23,
		PotatoBoy = 25,
		MeatboyEnding = 26,
		AlienHominid = 27,
		SprintMeatBoy = 28,
		Tim = 29,
		DefaultMeatBoy = 30
	};
		
	static MeatBoyCharactor* getCharacter(Type type)
	{
		MeatBoyCharactor** result = nullptr;

		int value = static_cast<int>(type);
		int* valueAddr = &value;

		__asm
		{
			push esi
			mov esi, value
			mov[ebp + 8], esi
			pop esi

			push valueAddr
			mov ecx, Offsets::Characters_ptr
			call Offsets::Characters_getCharacters
			mov result, eax
		}

		return *result;
	}
};
