#pragma once

#include "Memory/Offsets.hpp"
#include "MeatBoyCharactor.hpp"

class Unk1
{
public:
	// [[[Unk1+0x3C] + 0x34C] + 0x6DC]+0x384   TIMER
	char pad[0x18];		// +0
	MeatBoyCharactor* player;		// +24
	// +28
};

// sizeof: 144 (0x90)
class Window
{
public:
	char pad[0x64]; // +0
	Unk1* unk1;		// +100

	static Window* get()
	{
		return *(Window**)(Offsets::getAddr(0x0030BF28));
	}
};
