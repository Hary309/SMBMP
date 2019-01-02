#pragma once

#include <vector>
#include <memory>

#include <enet/enet.h>

#include <Types.hpp>

class NetPlayer;

class ClientManager
{
private:
	template<typename T>
	using Holder_t = std::vector<std::unique_ptr<T>>;

private:
	Holder_t<NetPlayer> clients;

	PlayerId lastId = 0;

public:
	ClientManager();
	~ClientManager();

	NetPlayer* add(ENetPeer* peer);

	void remove(ENetPeer* peer);
	void remove(NetPlayer* client);

	NetPlayer* getPlayer(PlayerId id);
	NetPlayer* getPlayer(ENetPeer* peer);

	uint32_t getSize() const { return static_cast<uint32_t>(clients.size()); }
	
	const auto& getClients() const { return clients; }
};
