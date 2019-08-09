/** @file GameShutdown_Hook.cpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#include "GameShutdown_Hook.hpp"

#include <Memory/MemMgr.hpp>
#include <SMB/Offsets.hpp>

#include "Client.hpp"

void GameShutdown()
{
	Client::get()->shutdown();
}

uintptr_t GameShutdown_Call;
uintptr_t GameShutdown_Retn;

void __declspec(naked) Asm_GameShutdown()
{
	__asm
	{
		pushad
			call GameShutdown_Call
		popad

		xor eax, eax
		pop esi
		mov esp, ebp

		jmp GameShutdown_Retn
	}
}

void Hook_GameShutdown()
{
	GameShutdown_Call = (uintptr_t)GameShutdown;
	GameShutdown_Retn = Offsets::getAddr(0x000F1D0E);

	MemMgr::JmpHook(Offsets::getAddr(0x000F1D09), (uintptr_t)Asm_GameShutdown);

	printf("GameShutdown hook initialized!\n");
}
