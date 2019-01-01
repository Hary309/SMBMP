#pragma once

#include "ClientManager.hpp"
#include "Network/NetServer.hpp"

class Server
{
private:
	ClientManager clientMgr;

	NetServer netServer;

	bool running = false;

public:
	Server();
	~Server();

	bool init();

	void update();

	bool isRunning() const { return running; }
};