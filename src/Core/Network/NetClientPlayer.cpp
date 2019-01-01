#include "NetClientPlayer.hpp"

#include <Network/NetBuffer.hpp>

#include "Client.hpp"
#include "NetClient.hpp"

NetClientPlayer::NetClientPlayer()
{
	player = &GSuperMeatBoy::get()->player;
}

NetClientPlayer::~NetClientPlayer()
{
}

void NetClientPlayer::update()
{
	// detect player's character change
	if (recentPlayerPtr != *player)
	{
		recentPlayerPtr = *player;

		int characterType = -1;

		if (recentPlayerPtr)
		{
			characterType = recentPlayerPtr->characterType;
		}

		NetBuffer buffer(PacketType::ClientCharacterChanged);
		buffer.write(characterType);
		Client::get()->getNetClient()->send(buffer);
	}

	// detect player move
	if (*player)
	{
		auto _player = *player;

		time_point currentTime = std::chrono::steady_clock::now();

		auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime-recentPositionUpdateTime).count();

		if (diff > 1000 / 15)
		{
			NetBuffer buffer(PacketType::ClientPositionUpdate);
			buffer.write(_player->pos.x);
			buffer.write(_player->pos.y);
			Client::get()->getNetClient()->send(buffer);

			recentPositionUpdateTime = currentTime;
		}
	}
}
