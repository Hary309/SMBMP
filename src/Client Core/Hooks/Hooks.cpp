#include "Hooks.hpp"

#include <windows.h>
#include <string>
#include <vector>
#include <fstream>

#include <Memory/Offsets.hpp>
#include <Memory/MemMgr.hpp>

#include <SMB.hpp>

#include "Common.hpp"

#include "TexturesHook.hpp"

std::vector<MeatBoyCharactor*> charactors;

void TestDraw()
{
	if (GetAsyncKeyState(VK_F5))
	{
		if (charactors.empty())
		{
			charactors.push_back(MeatBoyCharactor::createCharacter(Characters::Type::BandageGirl));
			charactors.push_back(MeatBoyCharactor::createCharacter(Characters::Type::Brownie));
			charactors.push_back(MeatBoyCharactor::createCharacter(Characters::Type::DrFetus));
			charactors.push_back(MeatBoyCharactor::createCharacter(Characters::Type::PotatoBoy));

			float last = 0.f;

			for (auto& ch : charactors)
			{
				ch->renderPos.x = last;
				last += 20.f;
			}
		}
	}

	if (!charactors.empty())
	{
		for (auto& ch : charactors)
		{
			ch->draw();
		}

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

	// disable exception handler
	MemMgr::MemSet(Offsets::getAddr(0x001DED31), 0xC3, 1);
	MemMgr::MemSet(Offsets::getAddr(0x001DED62), 0xC3, 1);

	// Hook_Textures();
}
