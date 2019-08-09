/** @file DefaultMeatBoy.cpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#include "DefaultMeatBoy.hpp"

#include "SMB.hpp"

DefaultMeatBoy::DefaultMeatBoy(MeatBoyCharactor* player, int number)
{
	__asm
	{
		push number
		push player
		mov ecx, this
		call Offsets::DefaultMeatBoy_DefaultMeatBoy
	}
}

DefaultMeatBoy::~DefaultMeatBoy()
{
}
