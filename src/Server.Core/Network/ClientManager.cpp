/** @file ClientManager.cpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#include "ClientManager.hpp"

#include <algorithm>

#include "NetPlayer.hpp"

ClientManager::ClientManager()
{
}

ClientManager::~ClientManager()
{
}

NetPlayer* ClientManager::add(ENetPeer* peer)
{
	auto client = new NetPlayer(lastId++, peer);
	
	peer->data = reinterpret_cast<void*>(client);

	clients.push_back(std::unique_ptr<NetPlayer>(client));

	return client;
}

void ClientManager::remove(ENetPeer* peer)
{
	auto it = std::find_if(clients.begin(), clients.end(), [&](auto& _client) { return _client->getPeer() == peer; });

	if (it != clients.end())
	{
		clients.erase(it);
	}
}

void ClientManager::remove(NetPlayer* client)
{
	auto it = std::find_if(clients.begin(), clients.end(), [&](auto& _client) { return _client.get() == client; });

	if (it != clients.end())
	{
		clients.erase(it);
	}
}

NetPlayer* ClientManager::getPlayer(PlayerId id)
{
	auto it = std::find_if(clients.begin(), clients.end(), [&](auto& _client) { return _client->getId() == id; });

	if (it != clients.end())
		return it->get();

	return nullptr;
}

NetPlayer* ClientManager::getPlayer(ENetPeer* peer)
{
	auto it = std::find_if(clients.begin(), clients.end(), [&](auto& _client) { return _client->getPeer() == peer; });

	if (it != clients.end())
		return it->get();

	return nullptr;
}
