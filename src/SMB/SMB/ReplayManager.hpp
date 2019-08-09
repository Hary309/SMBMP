/** @file ReplayManager.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

class ReplayManager
{
public:
	char pad1[0x2C];		// +0
	int ghostsNumber;		// +44 0x2C (how many ghosts replay have)
};
