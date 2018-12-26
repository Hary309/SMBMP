#include "DefaultMeatBoy.hpp"

#include "Memory/MemMgr.hpp"
#include "Memory/Offsets.hpp"

uintptr_t drawAddr = 0;
uintptr_t updateAddr = 0;

DefaultMeatBoy::DefaultMeatBoy(MeatBoyCharactor* player, int number)
{
	uintptr_t addr = Offsets::getAddr(0x000DB500);

	drawAddr = Offsets::getAddr(0x000DBFB0);
	updateAddr = Offsets::getAddr(0x000E2420);

	__asm
	{
		push number
		push player
		mov ecx, this
		call addr
	}
}

DefaultMeatBoy::~DefaultMeatBoy()
{
	//constexpr int asdf = sizeof(DefaultMeatBoy);
}

void DefaultMeatBoy::draw()
{
	__asm
	{
		mov ecx, this
		call drawAddr
	}
}

void DefaultMeatBoy::update()
{
	__asm
	{
		mov ecx, this
		call updateAddr
	}
}


