#include <Windows.h>
#include <iostream>

#include "Client.hpp"
#include "Memory/Offsets.hpp"

#include "Hooks/Hooks.hpp"


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

			printf("Witam\n");

			Client::setInstance(hinstDLL);

			Offsets::init();
			Hooks::Init();
		} break;
		case DLL_PROCESS_DETACH:
		{
			printf("Nara\n");
		} break;
	}

	return true;
}

