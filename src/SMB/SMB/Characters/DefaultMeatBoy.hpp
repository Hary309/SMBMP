/** @file DefaultMeatBoy.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include "SMB.hpp"

// sizeof: 2636 0xA4C
class DefaultMeatBoy : public MeatBoyCharactor
{
public:
	char pad32[80];

public:
	DefaultMeatBoy(MeatBoyCharactor* player, int number);
	~DefaultMeatBoy();
};
