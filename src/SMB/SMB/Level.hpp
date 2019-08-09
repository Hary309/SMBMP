/** @file Level.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include "SMB.hpp"

class Level
{
public:
	char pad[7468];		// +0
	Vector2f startPos;	// +7468
};
