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

struct Asdfff
{
	uintptr_t vtable;
};


Asdfff* Asdf()
{
	return *(Asdfff**)(Offsets::getAddr(0x0030A46C));
}


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

			//player1 = MeatBoyCharactor::createCharacter(Characters::Type::DefaultMeatBoy);  
			//player2 = MeatBoyCharactor::createCharacter(Characters::Type::DefaultMeatBoy);
			//player1 = new DefaultMeatBoy(data, 0);
			//player2 = new DefaultMeatBoy(data, 0);

			//player1 = new DefaultMeatBoy(GSuperMeatBoy::get()->player, 0);
			//player2 = new DefaultMeatBoy(GSuperMeatBoy::get()->player, 0);

			//player1 = Characters::getCharacter(Characters::Type::DefaultMeatBoy);
			//player2 = Characters::getCharacter(Characters::Type::DefaultMeatBoy);

			//printf("Postac: %p %p\n", player1, player2);

			//player1->renderPos.x = -200.f;
			//player2->renderPos.x = -100.f;
		}
	}


	if (GetAsyncKeyState(VK_F7))
	{
		//auto level = Level::get();

		//printf("%f %f\n", level->startPos.x, level->startPos.y);

		//level->loadLevel(1, 1);

		//Sleep(100);

	//	printf("%p\n", GSuperMeatBoy::get()->player->sprite->vtable);

		//printf("%p\n", Window::get()->vtable);
	}

	if (charactors.size())
	{
		/*if (GetAsyncKeyState(VK_F6))
		{
			defaultMeatBoy->pos = GSuperMeatBoy::get()->player->pos;
			defaultMeatBoy->renderPos = GSuperMeatBoy::get()->player->pos;
			defaultMeatBoy->animationType = GSuperMeatBoy::get()->player->animationType;
			//printf("%p\n", defaultMeatBoy);
			//defaultMeatBoy->update();
		}*/


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
