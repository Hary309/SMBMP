#pragma once

#include "Memory/Offsets.hpp"
#include "Vector.hpp"

class ReplayManager
{
public:
	char pad1[0x2C];	// +0
	int ghostNumber;	// +44 0x2C
};

class Player
{
public:
	char pad1[0x84];			// +0
	Vector2 pos;				// +132
	char pad2[0x10];			// +140
	Vector2 velocity;			// +156 0x9C
	char pad3[0x71C];			// +164 
	Player** ghosts;			// +1984 0x7C0 Array of pointers pointing to ghosts (Kurwa tablice wskaŸników do duszków xD)
	char pad4[0x218];			// +1988
	ReplayManager* replayMgr;	// +2524 0x9DC
	// +2528
};

class Unk1
{
public:
	// [[[Unk1+0x3C] + 0x34C] + 0x6DC]+0x384   TIMER
	char pad[0x18];		// +0
	Player* player;		// +24
	// +28
};

class GSuperMeatBoy
{
public:
	char pad[0x64];	// +0
	Unk1* unk1;		// +100
	// +104

	static GSuperMeatBoy* get()
	{
		return *(GSuperMeatBoy**)(Offsets::getAddr(0x0070BF28));
	}
};

class Camera
{
public:
	char pad[3296];		// +0
	Vector2 pos;		// +3296
	// +3304
};

class Costam
{
public:
	char pad[32];		// +0
	Camera* camera;		// +32
	// +36

	static Costam* get()
	{
		return *(Costam**)(Offsets::getAddr(0x0070A1A0));
	}

};
