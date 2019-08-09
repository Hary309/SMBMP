#pragma once

#include <stdint.h>

class Offsets
{
private:
	static uintptr_t baseAddr;

public:
	static uintptr_t Characters_ptr;
	static uintptr_t Characters_getCharacters;

	static uintptr_t GMeatHUD_ptr;

	static uintptr_t GSuperMeatBoy_ptr;

	static uintptr_t GSuperMeatBoy_RenderLayer_ptr;

	static uintptr_t LevelManager_ptr;
	static uintptr_t LevelManager_loadLevel;

	static uintptr_t MeatBoyCharactor_cloneCharactor;
	static uintptr_t DefaultMeatBoy_DefaultMeatBoy;

	static uintptr_t Renderer_ptr;

	static uintptr_t Window_ptr;

public:
	static void init();

	static uintptr_t getAddr(uintptr_t addr);

	static uintptr_t getBaseAddr();
};
