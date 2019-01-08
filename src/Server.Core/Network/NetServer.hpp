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
