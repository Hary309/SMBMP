#include "WndProc_Hook.hpp"

#include <Memory/MemMgr.hpp>
#include <Memory/Offsets.hpp>

#include "Client.hpp"

void WndProc(HWND hWnd, uint32_t Msg, WPARAM wParam, LPARAM lParam)
{
	printf("Msg: %d\n", Msg);
}

uintptr_t WndProc_Call;
uintptr_t WndProc_Retn;

void __declspec(naked) Asm_WndProc()
{
	__asm
	{
		pushad
			push	[ebp+20]
			push	[ebp+16]
			push	[ebp+12]
			push	[ebp+8]
			call	WndProc_Call
			add		esp, 16
		popad

		mov     eax, [ebp + 0Ch]
		cmp     eax, 10h

		jmp WndProc_Retn
	}
}

void Hook_WndProc()
{
	WndProc_Call = (uintptr_t)WndProc;
	WndProc_Retn = Offsets::getAddr(0x00055130);
	MemMgr::JmpHook(Offsets::getAddr(0x0005512A), (uintptr_t)Asm_WndProc);

	printf("WndProc hook initialized!\n");
}
