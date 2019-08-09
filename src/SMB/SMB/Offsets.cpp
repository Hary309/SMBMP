#include "Offsets.hpp"

#include <SMB.hpp>

#include <Windows.h>
#include <cstdio>

uintptr_t Offsets::baseAddr = 0;

uintptr_t Offsets::Characters_ptr;
uintptr_t Offsets::Characters_getCharacters;

uintptr_t Offsets::GMeatHUD_ptr;

uintptr_t Offsets::GSuperMeatBoy_ptr;

uintptr_t Offsets::GSuperMeatBoy_RenderLayer_ptr;

uintptr_t Offsets::LevelManager_ptr;
uintptr_t Offsets::LevelManager_loadLevel;

uintptr_t Offsets::MeatBoyCharactor_cloneCharactor;
uintptr_t Offsets::DefaultMeatBoy_DefaultMeatBoy;


uintptr_t Offsets::Renderer_ptr;

uintptr_t Offsets::Window_ptr;

void Offsets::init()
{
	baseAddr = (uintptr_t)GetModuleHandle(0);

	printf("Offsets initialized! Base address = %X or %X\n", baseAddr, getAddr(0x00481920) - 0x00481920);

	Characters_ptr = Offsets::getAddr(0x0030B2C0);
	Characters_getCharacters = Offsets::getAddr(0x000E9180);

	GMeatHUD_ptr = Offsets::getAddr(0x003098D8);

	GSuperMeatBoy_ptr = Offsets::getAddr(0x0030A1A0);

	GSuperMeatBoy_RenderLayer_ptr = Offsets::getAddr(0x0030B298);

	LevelManager_ptr = Offsets::getAddr(0x0030A46C);
	LevelManager_loadLevel = Offsets::getAddr(0x000AAB80);

	MeatBoyCharactor_cloneCharactor = Offsets::getAddr(0x000E9460);
	DefaultMeatBoy_DefaultMeatBoy = Offsets::getAddr(0x000DB500);

	Renderer_ptr = Offsets::getAddr(0x00311148);

	Window_ptr = Offsets::getAddr(0x0030BF28);
}

uintptr_t Offsets::getAddr(uintptr_t addr)
{
	return baseAddr + addr;
}

uintptr_t Offsets::getBaseAddr()
{
	return baseAddr;
}
