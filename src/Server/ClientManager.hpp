#pragma once

#include <vector>
#include <memory>

#include <enet/enet.h>

class NetPlayer;

class ClientManager
{
private:
	template<typename T>
	using Holder_t = std::vector<std::unique_ptr<T>>;

private:
	Holder_t<NetPlayer> clients;

	size_t lastId = 0;

public:
	ClientManager();
	~ClientManager();

	NetPlayer* add(ENetPeer* peer);

	void remove(ENetPeer* peer);
	void remove(NetPlayer* client);

	NetPlayer* getPlayer(size_t id);
	NetPlayer* getPlayer(ENetPeer* peer);

	size_t getSize() const { return clients.size(); }
	
	const auto& getClients() const { return clients; }
};
