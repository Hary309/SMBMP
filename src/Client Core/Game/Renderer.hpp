#pragma once

#include <d3d9.h>
#include <d3dx9.h>

#include "Memory/Offsets.hpp"

// sizeof: 12
class Renderer
{
public:
	IDirect3DDevice9* device;	// +0
	IDirect3D9* d3d;			// +4

	static Renderer* get()
	{
		return *(Renderer**)(Offsets::getAddr(0x00711148));
	}
};
