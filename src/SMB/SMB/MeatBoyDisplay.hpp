#pragma once

#include "SMB.hpp"

class MeatBoyDisplay
{
public:
	uintptr_t vtable;	// +0
	char pad[896];		// +4
	void* unk;			// +900 
};
