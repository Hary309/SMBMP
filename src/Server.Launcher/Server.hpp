/** @file Server.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include <Network/ClientManager.hpp>
#include <Network/NetServer.hpp>

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