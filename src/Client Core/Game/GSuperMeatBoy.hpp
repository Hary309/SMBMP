#pragma once

#include "Memory/Offsets.hpp"

#include "Vector.hpp"
#include "Camera.hpp"
#include "MeatBoyCharactor.hpp"
#include "RenderLayerObject.hpp"
#include "LevelManager.hpp"

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
	LevelManager* levelMgr;		// +36
	MeatBoyCharactor* player;	// +40
	// +44

	static GSuperMeatBoy* get()
	{
		return *(GSuperMeatBoy**)(Offsets::getAddr(0x0030A1A0));
	}
};

