#include "PlayerLayer_Hook.hpp"

#include <Memory/MemMgr.hpp>
#include <SMB/Offsets.hpp>

#include "Client.hpp"

void PlayerLayer()
{
	Client::get()->draw_playerLayer();
}

uintptr_t PlayerLayer_Call;
uintptr_t PlayerLayer_Retn;

void __declspec(naked) Asm_PlayerLayer()
{
	__asm
	{
		pushad
			call PlayerLayer_Call
		popad

		push    ebx
		mov     ebx, ecx
		xor     eax, eax

		jmp PlayerLayer_Retn
	}
}

void Hook_PlayerLayer()
{
	PlayerLayer_Call = (uintptr_t)PlayerLayer;
	PlayerLayer_Retn = Offsets::getAddr(0x000E9FC5);
	MemMgr::JmpHook(Offsets::getAddr(0x000E9FC0), (uintptr_t)Asm_PlayerLayer);

	printf("PlayerLayer hook initialized!\n");
}
