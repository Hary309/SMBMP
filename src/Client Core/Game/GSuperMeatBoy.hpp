#pragma once

#include "Memory/Offsets.hpp"

class Player
{
public:
	char pad1[0x84];	// +0
	float x;			// +132
	float y;			// +136
	char pad2[0x16];	// +140
	float velocityX;	// 0x9c
	float velocityY;	// 0xA0
	char pad3[0x71c];	// 0x7c0
	Player** ghosts; //Array of pointers pointing to ghosts (Kurwa tablice wskaŸników do duszków xD)
	// [Player + 0x9DC] + 0x2C  LICZBA DUSZKÓW
};

class Unk1
{
public:
	// [[[Unk1+0x3C] + 0x34C] + 0x6DC]+0x384   TIMER
	char pad[0x18];		// +0
	Player* player;		// +24
};

class GSuperMeatBoy
{
public:
	char pad[0x64];	// +0
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
