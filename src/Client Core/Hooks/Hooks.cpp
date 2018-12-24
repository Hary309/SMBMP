#include "Hooks.hpp"

#include <windows.h>

#include "Memory/Offsets.hpp"
#include "Memory/MemMgr.hpp"

#include "Game/Renderer.hpp"
#include "Game/GSuperMeatBoy.hpp"

#include "Common.hpp"

IDirect3DTexture9 *texture;
ID3DXSprite *sprite = nullptr;

uintptr_t RendererAddrCall;
uintptr_t RendererAddrRetn;

void RenderSth()
{
	if (GetAsyncKeyState(VK_F5))
	{
		HRESULT result = D3DXCreateTextureFromFile(Renderer::get()->device, GetFilePath("data/player.jpg"), &texture);
		
		printf("%s\n", GetFilePath("data/player.jpg"));

		if (FAILED(result))
		{
			printf("Cannot create texture: %s\n", GetDXErrorMsg(result));
		}

		result = D3DXCreateSprite(Renderer::get()->device, &sprite);

		if (FAILED(result))
		{
			printf("Cannot create sprite: %s\n", GetDXErrorMsg(result));
		}

		Sleep(100);

		//offsetOf(&IDirect3DDevice9::BeginScene());

		//GSuperMeatBoy::get()->unk1->player->x = 0.f;
		//GSuperMeatBoy::get()->unk1->player->y = 0.f;

		//Costam::get()->camera->posX = 0.f;
		//Costam::get()->camera->posY = 0.f;

		//auto plr = GSuperMeatBoy::get()->unk1->player;

		//printf("[%p] Pos:(%f, %f), Ghost:(%f, %f)\n", plr, plr->x, plr->y, plr->replayX, plr->replayY);

		//printf("Unk1: %p,  Player: %p\n", GSuperMeatBoy::get()->unk1, GSuperMeatBoy::get()->unk1->player);
	}
}

void Renderer()
{
	//RenderSth();

	//if (sprite)
	//{
	//	sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	//	D3DXMATRIX matrix;

	//	D3DXVECTOR2 center(0.f, 0.f);
	//	D3DXVECTOR2 scaling(0.002f, -0.002f);

	//	auto camera = Costam::get()->camera;

	//	//D3DXVECTOR2 pos(GSuperMeatBoy::get()->unk1->player->x / 640.f, GSuperMeatBoy::get()->unk1->player->y / 360.f);
	//	D3DXVECTOR2 pos(0.f, -camera->pos.y * 0.006f);

	//	//printf("%f %f\n", camera->posX, camera->posY);

	//	D3DXMatrixTransformation2D(&matrix, NULL, NULL, &scaling, nullptr, 0, &pos);
	//	sprite->SetTransform(&matrix);

	//	sprite->Draw(texture, 0, 0, 0, D3DCOLOR_ARGB(255, 255, 255, 255));

	//	sprite->End();
	//}

	if (GetAsyncKeyState(VK_F6))
	{
		printf("%d\n", GSuperMeatBoy::get()->unk1->player->replayMgr->ghostNumber);
	}
}

void __declspec(naked) Asm_RendererHook()
{
	__asm
	{
		pushad
			call RendererAddrCall
		popad

		push    ebp
		mov     ebp, esp
		sub     esp, 60h

		jmp RendererAddrRetn
	}
}

void Hook_Renderer()
{
	RendererAddrRetn = Offsets::getAddr(0x627A76);
	RendererAddrCall = (uintptr_t)Renderer;

	MemMgr::JmpHook(Offsets::getAddr(0x627A70), (uintptr_t)Asm_RendererHook);
}

void Hooks::Init()
{
	Hook_Renderer();
}
