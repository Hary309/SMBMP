#pragma once

#include "Game/MeatBoyCharactor.hpp"

// sizeof: 2636 0xA4C
class DefaultMeatBoy : public MeatBoyCharactor
{
public:
	char pad32[80];

public:
	DefaultMeatBoy(MeatBoyCharactor* player, int number);
	~DefaultMeatBoy();
};
