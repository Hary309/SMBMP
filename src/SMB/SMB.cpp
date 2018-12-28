#include "SMB.hpp"

#include <Memory/Offsets.hpp>

uintptr_t GameOffsets::Characters_ptr;
uintptr_t GameOffsets::Characters_getCharacters;

uintptr_t GameOffsets::GMeatHUD_ptr;

uintptr_t GameOffsets::GSuperMeatBoy_ptr;

uintptr_t GameOffsets::GSuperMeatBoy_RenderLayer_ptr;

uintptr_t GameOffsets::LevelManager_ptr;
uintptr_t GameOffsets::LevelManager_loadLevel;

uintptr_t GameOffsets::MeatBoyCharactor_cloneCharactor;
uintptr_t GameOffsets::DefaultMeatBoy_DefaultMeatBoy;

uintptr_t GameOffsets::Renderer_ptr;

uintptr_t GameOffsets::Window_ptr;

void GameOffsets::init()
{
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
