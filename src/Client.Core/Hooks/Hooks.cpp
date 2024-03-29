/** @file Hooks.cpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#include "Hooks.hpp"

#include <windows.h>
#include <string>
#include <vector>
#include <fstream>

#include <SMB/Offsets.hpp>
#include <Memory/MemMgr.hpp>

#include <SMB.hpp>

#include "Common.hpp"

#include "GameInit_Hook.hpp"
#include "GameShutdown_Hook.hpp"
#include "WndProc_Hook.hpp"
#include "PlayerLayer_Hook.hpp"
#include "MainLoop_Hook.hpp"
#include "TextureLoad_Hook.hpp"


void Hooks::init()
{
	//Hook_WndProc();
	Hook_GameInit();
	Hook_GameShutdown();
	Hook_PlayerLayer();
	Hook_MainLoop();

	// disable printf
	MemMgr::MemSet(Offsets::getAddr(0x0011B7BC), 0x90, 5);

	// disable exception handler
	MemMgr::MemSet(Offsets::getAddr(0x001DED31), 0xC3, 1);
	MemMgr::MemSet(Offsets::getAddr(0x001DED62), 0xC3, 1);

	// allow run multiple games
	MemMgr::JmpHook(Offsets::getAddr(0x00053FF1), Offsets::getAddr(0x00054003));
}
