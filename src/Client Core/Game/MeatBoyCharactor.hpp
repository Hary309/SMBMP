#pragma once

#include "SceneObject2D.hpp"
#include "Vector.hpp"
#include "ReplayManager.hpp"

class MeatBoyCharactor : SceneObject2D
{
public:
	char pad1[116];				// +0
	Vector2 pos;				// +132
	char pad2[0x10];			// +140
	Vector2 velocity;			// +156 0x9C
	char pad3[0x34];			// +164 
	void* texture;				// +216 (maybe sprite)
	char pad4[1752];			// +220 
	int animationType;			// +1972
	int unk1;					// +1976
	int unk2;					// +1980
	MeatBoyCharactor** ghosts;	// +1984 0x7C0 Array of pointers pointing to ghosts (Kurwa tablice wskaźników do duszków xD)
	char pad5[88];				// +1988
	Vector2 renderPos;			// +2076
	char pad6[440];				// +2084
	ReplayManager* replayMgr;	// +2524 0x9DC
	char pad7[20];				// +2528
	int characterType;			// +2548 default: 0 (DefaultMeatBoy)
	char pad8[76];				// +2552
	int ghostIndex;				// +2628 
	// +2552
};
