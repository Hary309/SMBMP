#pragma once

class ReplayManager
{
public:
	char pad1[0x2C];		// +0
	int ghostsNumber;		// +44 0x2C (how many ghosts replay have)
};
