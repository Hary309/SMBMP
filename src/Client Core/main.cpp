#include <Windows.h>
#include <iostream>

#include <Memory/Offsets.hpp>
#include <Hooks/Hooks.hpp>

#include <SMB.hpp>

#include "Client.hpp"


BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			DisableThreadLibraryCalls(hinstDLL);
			AllocConsole();
			freopen("CONOUT$", "w", stdout);
			freopen("CONIN$", "r", stdin);

			Client::setInstance(hinstDLL);

			Offsets::init();
			GameOffsets::init();
			Hooks::Init();
		} break;
		case DLL_PROCESS_DETACH:
		{
			printf("Nara\n");
		} break;
	}

	return true;
}

