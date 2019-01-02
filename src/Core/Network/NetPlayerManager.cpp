#include "NetPlayerManager.hpp"

#include <algorithm>

#include "NetPlayer.hpp"

NetPlayerManager::NetPlayerManager()
{

}

NetPlayerManager::~NetPlayerManager()
{

}

void NetPlayerManager::update()
{
	localPlayer.update();

	for (auto& player : players)
	{
		player->update();
	}
}

void NetPlayerManager::draw_playerLayer()
{
	for (auto& player : players)
	{
		player->draw();
	}
}

NetPlayer* NetPlayerManager::add(PlayerId id)
{
	auto player = new NetPlayer(id);

	players.push_back(std::unique_ptr<NetPlayer>(player));

	return player;
}

void NetPlayerManager::remove(PlayerId id)
{
	auto it = std::find_if(players.begin(), players.end(), [&](auto& player) { return player->getId() == id; });

	if (it != players.end())
	{
		players.erase(it);
	}
}

void NetPlayerManager::remove(NetPlayer* player)
{
	auto it = std::find_if(players.begin(), players.end(), [&](auto& _player) { return _player.get() == player; });

	if (it != players.end())
	{
		players.erase(it);
	}
}

NetPlayer* NetPlayerManager::getPlayer(PlayerId id)
{
	auto it = std::find_if(players.begin(), players.end(), [&](auto& player) { return player->getId() == id; });
	
	if (it != players.end())
	{
		return it->get();
	}

	return nullptr;
}
