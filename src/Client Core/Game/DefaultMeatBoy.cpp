#include "DefaultMeatBoy.hpp"

#include "Memory/MemMgr.hpp"
#include "Memory/Offsets.hpp"

uintptr_t drawAddr = 0;

DefaultMeatBoy::DefaultMeatBoy(MeatBoyCharactor* player, int number)
{
	uintptr_t addr = Offsets::getAddr(0x000DB500);

	drawAddr = Offsets::getAddr(0x000DBFB0);

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
