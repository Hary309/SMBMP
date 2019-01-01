#pragma once

#include <enet/enet.h>

#include <Network/NetBuffer.hpp>

class NetPlayerManager;

class NetClient
{
private:
	ENetHost* client = nullptr;
	ENetPeer* serverPeer = nullptr;

	NetPlayerManager* netPlayerMgr = nullptr;

public:
	static constexpr int TickRate = 30;

private:
	void processPacket(NetBuffer& packet, ENetPeer* peer);

public:
	NetClient(NetPlayerManager* netPlayerManager);
	~NetClient();

	bool connect(const char* ip, short port);

	void update();

	void send(NetBuffer& packet);
};