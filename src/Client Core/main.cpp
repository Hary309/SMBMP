#include <Windows.h>
#include <iostream>
#include <thread>


#include "Memory/Offsets.h"

#include "Game/GSuperMeatBoy.h"
#include "Game/Renderer.hpp"
#include "Hooks/Hooks.h"




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

			//CreateThread(NULL,0,thread,NULL,0,NULL);


			Offsets::init();
			initHooks();
		} break;
		case DLL_PROCESS_DETACH:
		{
			printf("Nara\n");
		} break;
	}

	return true;
}

