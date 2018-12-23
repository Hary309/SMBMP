#pragma once

#include "Memory/Offsets.hpp"

class Player
{
public:
	char pad1[132];		// +0
	float x;			// +132
	float y;			// +136
	char pad2[16];		// +140
	float replayX;		// +156
	float replayY;		// +160
};

class Unk1
{
public:
	char pad[24];		// +0
	Player* player;		// +24
};

class GSuperMeatBoy
{
public:
	char pad[100];	// +0
	Unk1* unk1;		// +100

	static GSuperMeatBoy* get()
	{
		return *(GSuperMeatBoy**)(Offsets::getAddr(0x0070BF28));
	}
};

class Camera
{
public:
	char pad[3296];		// +0
	float posX;			// +3296
	float posY;			// +3300
};

class Costam
{
public:
	char pad[32];		// +0
	Camera* camera;		// +32

	static Costam* get()
	{
		return *(Costam**)(Offsets::getAddr(0x0070A1A0));
	}

};
