#include "Server.hpp"

Server::Server()
	: clientMgr(), netServer(&clientMgr)
{
}

Server::~Server()
{
}

bool Server::init()
{
	netServer.init(1234);
	running = true;

	return true;
}

void Server::update()
{
	netServer.update();
}
