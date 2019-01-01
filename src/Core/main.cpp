#include "Client.hpp"

#include <Windows.h>
#include <iostream>

std::unique_ptr<Client> client;

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

			client = std::make_unique<Client>(hinstDLL);
		} break;
		case DLL_PROCESS_DETACH:
		{
			FreeConsole();
			client.reset();
		} break;
	}

	return true;
}

