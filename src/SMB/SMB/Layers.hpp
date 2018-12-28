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
		return *(GSuperMeatBoy_RenderLayer**)(GameOffsets::GSuperMeatBoy_RenderLayer_ptr);
	}
};