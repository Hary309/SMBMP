/** @file Camera.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include "SMB.hpp"

class Camera
{
public:
	char pad[3296];		// +0
	Vector2f pos;		// +3296
	// +3304
};
