#pragma once

#include "SMB.hpp"

// sizeof: 8
class Game
{
public:
	uintptr_t vtable_Game;
	uintptr_t unk4;
};

// sizeof: 928
class GSuperMeatBoy : public RenderLayerObject, Game
{
public:
	// RenderLayerObject		// +0
	// Game						// +16
	int unk5;					// +24
	int unk6;					// +28
	Camera* camera;				// +32
	Level* currentLevel;		// +36
	MeatBoyCharactor* player;	// +40
	// +44

	static GSuperMeatBoy* get()
	{
		return *(GSuperMeatBoy**)(GameOffsets::GSuperMeatBoy_ptr);
	}
};

