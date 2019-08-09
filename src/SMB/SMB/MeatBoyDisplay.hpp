/** @file MeatBoyDisplay.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include "SMB.hpp"

class MeatBoyDisplay
{
public:
	uintptr_t vtable;	// +0
	char pad[896];		// +4
	void* unk;			// +900 
};
