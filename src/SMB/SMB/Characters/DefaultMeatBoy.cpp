#include "DefaultMeatBoy.hpp"

#include "SMB.hpp"

DefaultMeatBoy::DefaultMeatBoy(MeatBoyCharactor* player, int number)
{
	__asm
	{
		push number
		push player
		mov ecx, this
		call GameOffsets::DefaultMeatBoy_DefaultMeatBoy
	}
}

DefaultMeatBoy::~DefaultMeatBoy()
{
}
