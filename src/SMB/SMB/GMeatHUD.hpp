/** @file GMeatHUD.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include "SMB.hpp"

// sizeof: 1004
class GMeatHUD : public RenderLayer
{
public:
	char pad[900];	// +0
	float time;		// +900

	static GMeatHUD* get()
	{
		return *(GMeatHUD**)(Offsets::GMeatHUD_ptr);
	}
};
