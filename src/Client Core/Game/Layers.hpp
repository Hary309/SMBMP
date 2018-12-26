#pragma once

#include "MeatBoyCharactor.hpp"
#include "Memory/Offsets.hpp"

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
		return *(GSuperMeatBoy_RenderLayer**)(Offsets::getAddr(0x0030B298));
	}
};
