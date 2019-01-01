#pragma once

#include <vector>
#include <memory>

#include "NetClientPlayer.hpp"

class NetPlayer;

class NetPlayerManager
{
private:
	template<typename T>
	using Holder_t = std::vector<std::unique_ptr<T>>;

private:
	Holder_t<NetPlayer> players;

	NetClientPlayer localPlayer;

public:
	NetPlayerManager();
	~NetPlayerManager();

	void update();
	void draw_playerLayer();

	NetPlayer* add(size_t id);
	void remove(size_t id);
	void remove(NetPlayer* player);

	NetPlayer* getPlayer(size_t id);

	size_t getSize() const { return players.size(); }

	NetClientPlayer* getLocalPlayer() { return &localPlayer; }
	const auto& getPlayers() const { return players; }
};