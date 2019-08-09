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
