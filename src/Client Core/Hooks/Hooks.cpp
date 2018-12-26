#include "Hooks.hpp"

#include <windows.h>
#include <string>
#include <fstream>

#include "Memory/Offsets.hpp"
#include "Memory/MemMgr.hpp"

#include "Game/Renderer.hpp"
#include "Game/GSuperMeatBoy.hpp"
#include "Game/Characters/DefaultMeatBoy.hpp"

#include "Common.hpp"

#include "TexturesHook.hpp"

MeatBoyCharactor* player1 = nullptr;
MeatBoyCharactor* player2 = nullptr;



void TestDraw()
{
	if (GetAsyncKeyState(VK_F5))
	{
		if (player1 == nullptr)
		{
			player1 = MeatBoyCharactor::createCharacter(Characters::Type::DefaultMeatBoy);  
			player2 = MeatBoyCharactor::createCharacter(Characters::Type::DefaultMeatBoy);

			//player1 = new DefaultMeatBoy(GSuperMeatBoy::get()->player, 0);
			//player2 = new DefaultMeatBoy(GSuperMeatBoy::get()->player, 0);

			//player1 = Characters::getCharacter(Characters::Type::DefaultMeatBoy);
			//player2 = Characters::getCharacter(Characters::Type::DefaultMeatBoy);

			printf("Postac: %p %p\n", player1, player2);

			player1->renderPos.x = -200.f;
			player2->renderPos.x = -100.f;
		}
	}

	if (GetAsyncKeyState(VK_F7))
	{
		//printf("%p\n", Window::get()->vtable);
	}

	if (player1)
	{
		/*if (GetAsyncKeyState(VK_F6))
		{
			defaultMeatBoy->pos = GSuperMeatBoy::get()->player->pos;
			defaultMeatBoy->renderPos = GSuperMeatBoy::get()->player->pos;
			defaultMeatBoy->animationType = GSuperMeatBoy::get()->player->animationType;
			//printf("%p\n", defaultMeatBoy);
			//defaultMeatBoy->update();
		}*/

		player1->draw();
		player2->draw();
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
