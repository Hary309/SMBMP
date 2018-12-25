#pragma once

#include "Memory/Offsets.hpp"
#include "Vector.hpp"

class ReplayManager
{
public:
	char pad1[0x2C];		// +0
	int ghostsNumber;		// +44 0x2C (how many ghosts replay have
};


class RenderLayerObject
{
public:
	uintptr_t vtable_RenderLayerObject;
};

class SceneObject : RenderLayerObject
{
public:
};

class SceneObject2D : SceneObject
{
public:
};

class MeatBoyCharactor : SceneObject2D
{
public:
	char pad1[0x80];			// +0
	Vector2 pos;				// +132
	char pad2[0x10];			// +140
	Vector2 velocity;			// +156 0x9C
	char pad3[0x34];			// +164 
	void* texture;				// +216 (maybe sprite)
	char pad4[1752];			// +220 
	int animationType;			// +1972
	int unk1;					// +1976
	int unk2;					// +1980
	MeatBoyCharactor** ghosts;	// +1984 0x7C0 Array of pointers pointing to ghosts (Kurwa tablice wskaŸników do duszków xD)
	char pad5[0x218];			// +1988
	ReplayManager* replayMgr;	// +2524 0x9DC
	char pad6[0x14];			// +2528
	int characterType;			// +2548 default: 0 (DefaultMeatBoy)
	int ghostIndex;				// +2628 
	// +2552
};


// sizeof: 240 0xF0
class Sprite : SceneObject2D
{
};

class Unk1
{
public:
	// [[[Unk1+0x3C] + 0x34C] + 0x6DC]+0x384   TIMER
	char pad[0x18];		// +0
	MeatBoyCharactor* player;		// +24
	// +28
};

class Game
{
public:
	uintptr_t vtable_Game;

};

class GSuperMeatBoy : public RenderLayerObject, Game
{
public:
	char pad[0x5C];	// +0
	Unk1* unk1;		// +100
	// +104

	static GSuperMeatBoy* get()
	{
		return *(GSuperMeatBoy**)(Offsets::getAddr(0x0030BF28));
	}
};

class Camera
{
public:
	char pad[3296];		// +0
	Vector2 pos;		// +3296
	// +3304
};

class SMB_dword_D6A1A0
{
public:
	char pad[32];		// +0
	Camera* camera;		// +32
	// +36

	static SMB_dword_D6A1A0* get()
	{
		return *(SMB_dword_D6A1A0**)(Offsets::getAddr(0x0030A1A0));
	}

};
