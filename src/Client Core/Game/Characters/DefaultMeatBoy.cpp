#include "DefaultMeatBoy.hpp"

#include "Memory/MemMgr.hpp"
#include "Memory/Offsets.hpp"

DefaultMeatBoy::DefaultMeatBoy(MeatBoyCharactor* player, int number)
{
	uintptr_t addr2 = Offsets::getAddr(0x000DB500);


	__asm
	{
		push number
		push player
		mov ecx, this
		call addr2
	}
}

DefaultMeatBoy::~DefaultMeatBoy()
{
}



