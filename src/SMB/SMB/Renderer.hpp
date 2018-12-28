#pragma once

#include "SMB.hpp"

// sizeof: 12
class Renderer
{
public:
	IDirect3DDevice9* device;	// +0
	IDirect3D9* d3d;			// +4
	// +8

	static Renderer* get()
	{
		return *(Renderer**)(GameOffsets::Renderer_ptr);
	}
};
