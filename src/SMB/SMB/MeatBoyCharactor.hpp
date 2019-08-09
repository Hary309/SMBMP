/** @file MeatBoyCharactor.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include "SMB.hpp"

class MeatBoyCharactorVTable
{
public:
	char pad[28];
	void(__thiscall *update)(MeatBoyCharactor*);
	void(__thiscall *draw)(MeatBoyCharactor*);
};

class MeatBoyCharactor //: public SceneObject2D
{
public:
	MeatBoyCharactorVTable* vtable; // +0
	char pad1[128];					// +4
	Vector2f pos;					// +132
	char pad2[0x10];				// +140
	Vector2f velocity;				// +156 0x9C
	char pad3[0x34];				// +164 
	MeatBoyDisplay* display;		// +216
	char pad4[1746];				// +220 
	int animation1;					// +1968
	int animation2;					// +1972
	int animation3;					// +1976
	int unk2;						// +1980
	MeatBoyCharactor** ghosts;		// +1984 0x7C0 Array of pointers pointing to ghosts
	char pad5[88];					// +1988
	Vector2f renderPos;				// +2076
	char pad6[440];					// +2084
	ReplayManager* replayMgr;		// +2524 0x9DC
	char pad7[12];					// +2528
	int animation4;					// +2540
	int unk3;						// +2544
	int characterType;				// +2548 default: 0 (DefaultMeatBoy)
	char pad8[76];					// +2552
	int ghostIndex;					// +2628 
	// +2552


public:
	void setPosition(const Vector2f& pos)
	{
		this->pos = pos;
		this->renderPos = pos;
	}

	static MeatBoyCharactor* cloneCharacter(MeatBoyCharactor* character)
	{
		MeatBoyCharactor* result = nullptr;

		__asm
		{
			push 0
			push character
			call Offsets::MeatBoyCharactor_cloneCharactor
			mov result, eax
		}

		return result;
	}

	static MeatBoyCharactor* createCharacter(Characters::Type type)
	{
		auto character = Characters::getCharacter(type);
		return cloneCharacter(character);
	}

	void update()
	{
		vtable->update(this);
	}

	void draw()
	{
		vtable->draw(this);
	}
};
