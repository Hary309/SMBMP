#include "Hooks.h"

#include <DxErr.h>

#include "Memory/Offsets.h"
#include "Memory/MemMgr.h"

#include "Game/Renderer.hpp"
#include "Game/GSuperMeatBoy.h"

struct CUSTOMVERTEX { FLOAT X, Y, Z, RHW; DWORD COLOR; };
#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)


IDirect3DTexture9 *texture;
ID3DXSprite *sprite = nullptr;


uintptr_t RendererAddrCall;
uintptr_t RendererAddrRetn;


int (WINAPIV * __vsnprintf)(char *, size_t, const char*, va_list) = _vsnprintf;

const char * GetDXErrorMsg(HRESULT result)
{
	const unsigned bufferSize = 256;

	char localError[bufferSize];
	char *error = new char[bufferSize];

	sprintf_s(localError, "%s - %s", DXGetErrorString(result), DXGetErrorDescription(result));

	memcpy(error, localError, bufferSize);

	return error;
}


void RenderSth()
{
	if (GetAsyncKeyState(VK_F5))
	{
		printf("%p\n", Renderer::get()->device);


		HRESULT result = D3DXCreateTextureFromFile(Renderer::get()->device, "C:\\Projects\\SMB-MP\\src\\Release\\player.jpg", &texture);

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
	RenderSth();

	if (sprite)
	{
		sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
		D3DXMATRIX matrix;

		D3DXVECTOR2 center(0.f, 0.f);
		D3DXVECTOR2 scaling(0.002f, 0.002f);

		D3DXVECTOR2 pos(GSuperMeatBoy::get()->unk1->player->x, GSuperMeatBoy::get()->unk1->player->y);

		D3DXMatrixTransformation2D(&matrix, NULL, NULL, &scaling, nullptr, 0, &pos);
		sprite->SetTransform(&matrix);

		sprite->Draw(texture, 0, 0, 0, D3DCOLOR_ARGB(255, 255, 255, 255));

		sprite->End();
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

void initHooks()
{
	Hook_Renderer();

	//asdf();

}
