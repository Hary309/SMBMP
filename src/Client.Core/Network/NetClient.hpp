/** @file NetClient.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

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
	static constexpr int TickRate = 15;

private:
	void processPacket(NetBuffer& packet, ENetPeer* peer);

public:
	NetClient(NetPlayerManager* netPlayerManager);
	~NetClient();

	bool connect(const char* ip, short port);

	void update();

	void send(NetBuffer& packet);
};