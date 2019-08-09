/** @file NetServer.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include <vector>

#include <enet/enet.h>

#include <Network/NetBuffer.hpp>

class ClientManager;

class NetServer
{
private:
	ENetHost* server = nullptr;

	ClientManager* clientMgr;

private:
	void processPacket(NetBuffer& packet, ENetPeer* peer);

public:
	NetServer(ClientManager* clientMgr);
	~NetServer();

	bool init(short port);

	void update();

	// send to all
	void send(NetBuffer& packet);

	// send to one specified client
	void send(NetBuffer& packet, ENetPeer* client);

	// send to multi specified clients
	void send(NetBuffer& packet, const std::vector<ENetPeer*>& clients);
};
