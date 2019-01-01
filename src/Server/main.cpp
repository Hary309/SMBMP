#include <iostream>

#include "Server.hpp"

#ifdef WIN32
#include <Windows.h>
#endif


int main()
{
	Server server;

	if (!server.init())
		return 1;

	while (server.isRunning())
	{
		server.update();

	#ifdef WIN32
		Sleep(10);
	#endif
	}

}