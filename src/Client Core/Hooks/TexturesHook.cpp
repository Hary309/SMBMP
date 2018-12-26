#include "TexturesHook.hpp"

#include <fstream>
#include <string>

#include "Memory/Offsets.hpp"
#include "Memory/MemMgr.hpp"

uintptr_t LoadTextureAddrCall;
uintptr_t LoadTextureAddrRetn;

void LoadTexture_Print(void* addr, void* data, int size)
{
	printf("Addr: %p Size: %d\n", addr, size);

	std::ofstream file("addr_" + std::to_string((uintptr_t)addr) + ".png", std::ofstream::binary);

	file.write((const char*)data, size);
	file.close();
}

void __declspec(naked) Asm_LoadTexture()
{
	__asm
	{
		pushad
		push[esi + 8]
		push[esi + 4]
		push[ebp - 30h]
		call	LoadTextureAddrCall
		add		esp, 12
		popad

		mov ecx, [ebp - 3Ch]
		mov eax, [ebp - 30h]

		jmp LoadTextureAddrRetn
	}
}

void Hook_Textures()
{
	LoadTextureAddrCall = (uintptr_t)LoadTexture_Print;
	LoadTextureAddrRetn = Offsets::getAddr(0x629182);

	MemMgr::JmpHook(Offsets::getAddr(0x62917C), (uintptr_t)Asm_LoadTexture);
}

