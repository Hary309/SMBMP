/** @file NetPlayerManager.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

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

	NetPlayer* add(PlayerId id);
	void remove(PlayerId id);
	void remove(NetPlayer* player);

	NetPlayer* getPlayer(PlayerId id);

	uint32_t getSize() const { return static_cast<uint32_t>(players.size()); }

	NetClientPlayer* getLocalPlayer() { return &localPlayer; }
	const auto& getPlayers() const { return players; }
};