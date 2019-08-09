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

	// send player's pos
	if (*player)
	{
		auto _player = *player;

		auto currentTime = GetTickCount64();

		auto diff = currentTime - recentPositionUpdateTime;

		if (diff > 1000 / NetClient::TickRate)
		{
			NetBuffer buffer(PacketType::ClientPositionUpdate);
			buffer.write(_player->pos.x);
			buffer.write(_player->pos.y);
			Client::get()->getNetClient()->send(buffer);

			buffer.reset(PacketType::ClientAnimationChanged);
			buffer.write(_player->animation1);
			buffer.write(_player->animation2);
			buffer.write(_player->animation4);
			Client::get()->getNetClient()->send(buffer);

			recentPositionUpdateTime = currentTime;
		}
	}
}
