#pragma once

#include <enet/enet.h>

class NetPlayer
{
private:
	size_t id = 0;
	ENetPeer* peer = nullptr;

public:
	NetPlayer(size_t id, ENetPeer* peer)
		: id(id), peer(peer)
	{
	}

	size_t getId() const { return id; }
	ENetPeer* getPeer() const { return peer; }
};