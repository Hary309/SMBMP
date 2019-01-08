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
