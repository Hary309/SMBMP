#include "GameInit_Hook.hpp"

#include <Memory/MemMgr.hpp>
#include <Memory/Offsets.hpp>

#include "Client.hpp"

void GameInit()
{
	Client::get()->init();
}

uintptr_t GameInit_Call;
uintptr_t GameInit_Retn;

void __declspec(naked) Asm_GameInit()
{
	__asm
	{
		pushad
			call GameInit_Call
		popad

		pop ecx
		pop edi
		pop esi
		pop ebx
		mov ecx, [ebp - 10h]

		jmp GameInit_Retn
	}
}

void Hook_GameInit()
{
	GameInit_Call = (uintptr_t)GameInit;
	GameInit_Retn = Offsets::getAddr(0x000679EF);

	MemMgr::JmpHook(Offsets::getAddr(0x000679E8), (uintptr_t)Asm_GameInit);
}
