#pragma once

#include "SMB.hpp"

// sizeof: 12
class Renderer
{
public:
	IDirect3DDevice* device;	// +0
	IDirect3D* d3d;				// +4

	// +8

	static Renderer* get()
	{
		return *(Renderer**)(GameOffsets::Renderer_ptr);
	}
};
