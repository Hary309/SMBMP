/** @file Window.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include "SMB.hpp"

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
		return *(Window**)(Offsets::Window_ptr);
	}
};
