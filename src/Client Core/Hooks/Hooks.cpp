#include "Hooks.hpp"

#include <windows.h>
#include <string>
#include <fstream>

#include "Memory/Offsets.hpp"
#include "Memory/MemMgr.hpp"

#include "Game/Renderer.hpp"
#include "Game/GSuperMeatBoy.hpp"
#include "Game/DefaultMeatBoy.hpp"

#include "Common.hpp"

#include "TexturesHook.hpp"

DefaultMeatBoy* defaultMeatBoy = nullptr;

void TestDraw()
{
	if (GetAsyncKeyState(VK_F5))
	{
		if (defaultMeatBoy == nullptr)
		{
			defaultMeatBoy = new DefaultMeatBoy(SMB_dword_D6A1A0::get()->player, 0);

			printf("Created!\n");
		}
	}

	if (GetAsyncKeyState(VK_F6))
	{
		if (defaultMeatBoy)
		{
			defaultMeatBoy->pos = SMB_dword_D6A1A0::get()->player->pos;
		}
	}

	if (defaultMeatBoy)
	{
		defaultMeatBoy->draw();
	}
}


uintptr_t DrawAddr_Call;
uintptr_t DrawAddr_Retn;

void __declspec(naked) Asm_Draw()
{
	__asm
	{
		pushad
			call DrawAddr_Call
		popad

		push    ebx
		mov     ebx, ecx
		xor     eax, eax

		jmp DrawAddr_Retn
	}
}

void Hook_Draw()
{
	DrawAddr_Call = (uintptr_t)TestDraw;

	DrawAddr_Retn = Offsets::getAddr(0x000E9FC5);
	MemMgr::JmpHook(Offsets::getAddr(0x000E9FC0), (uintptr_t)Asm_Draw);
}

void Hooks::Init()
{
	Hook_Draw();

	// disable printf
	MemMgr::MemSet(Offsets::getAddr(0x0011B7BC), 0x90, 5);

	// Hook_Textures();
}
