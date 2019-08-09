/** @file RenderLayerObject.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include "SMB.hpp"

// sizeof: 16
class RenderLayerObject
{
public:
	uintptr_t vtable_RenderLayerObject;		// +0
	int unk1;								// +4
	int unk2;								// +8
	int unk3;								// +12
	// +16
};
