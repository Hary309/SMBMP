/** @file Layers.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include "SMB.hpp"

class RenderLayer
{

};

class GSuperMeatBoy_RenderLayer : public RenderLayer
{
public:
	char pad1[24];					// +0
	int charactersNumber;			// +24
	char pad2[12];					// +28
	MeatBoyCharactor** characters;	// +40

	static GSuperMeatBoy_RenderLayer* get()
	{
		return *(GSuperMeatBoy_RenderLayer**)(Offsets::GSuperMeatBoy_RenderLayer_ptr);
	}
};
