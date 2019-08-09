/** @file Renderer.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

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
		return *(Renderer**)(Offsets::Renderer_ptr);
	}
};
