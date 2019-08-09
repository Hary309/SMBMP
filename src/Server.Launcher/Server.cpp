/** @file Server.cpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#include "Server.hpp"

#include <Shared.Network.hpp>

Server::Server()
	: clientMgr(), netServer(&clientMgr)
{
}

Server::~Server()
{
}

bool Server::init()
{
	netServer.init(ServerPort);
	running = true;

	return true;
}

void Server::update()
{
	netServer.update();
}
