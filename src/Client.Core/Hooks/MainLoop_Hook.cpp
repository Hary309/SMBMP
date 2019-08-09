#include "MainLoop_Hook.hpp"

#include <Memory/MemMgr.hpp>
#include <SMB/Offsets.hpp>

#include "Client.hpp"

void MainLoop()
{
	Client::get()->update();
}

uintptr_t MainLoop_Call;
uintptr_t MainLoop_Retn;

void __declspec(naked) Asm_MainLoop()
{
	__asm
	{
		pushad
			call MainLoop_Call
		popad

		mov     edi, eax
		mov     ecx, eax
		mov[esi + 4Ch], edi

		jmp MainLoop_Retn
	}
}

void Hook_MainLoop()
{
	MainLoop_Call = (uintptr_t)MainLoop;
	MainLoop_Retn = Offsets::getAddr(0x000F8662);
	MemMgr::JmpHook(Offsets::getAddr(0x000F865B), (uintptr_t)Asm_MainLoop);

	printf("MainLoop hook initialized!\n");
}
