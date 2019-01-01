#include "NetClient.hpp"

#include "NetPlayerManager.hpp"
#include "NetPlayer.hpp"

NetClient::NetClient(NetPlayerManager* netPlayerMgr)
	: netPlayerMgr(netPlayerMgr)
{
}

NetClient::~NetClient()
{
	if (client)
	{
		// say goodbye
		enet_peer_disconnect_now(serverPeer, 0);

		enet_host_destroy(client);
	}

	enet_deinitialize();
}

bool NetClient::connect(const char* ip, short port)
{
	if (enet_initialize() != 0)
		return false;

	client = enet_host_create(nullptr, 1, 2, 0, 0);

	if (!client)
		return false;

	ENetAddress address;
	enet_address_set_host(&address, ip);
	address.port = port;

	serverPeer = enet_host_connect(client, &address, 2, 0);

	if (!serverPeer)
		return false;

	printf("Connecting to %s:%d\n", ip, port);

	return true;
}

void NetClient::update()
{
	ENetEvent event;

	while (enet_host_service(client, &event, 0) > 0)
	{
		switch (event.type)
		{
			case ENET_EVENT_TYPE_CONNECT:
			{
				printf("Connected!\n");

				NetBuffer buffer(PacketType::ClientConnected);
				send(buffer);
			} break;
			case ENET_EVENT_TYPE_RECEIVE:
			{
				NetBuffer packet(event.packet->data, event.packet->dataLength);

				processPacket(packet, event.peer);

				enet_packet_destroy(event.packet);
			} break;
			case ENET_EVENT_TYPE_DISCONNECT:
			{
				printf("Disconnected.\n");
			} break;
		}
	}
}

void NetClient::processPacket(NetBuffer& packet, ENetPeer* peer)
{
	switch (packet.getPacketType())
	{
		case PacketType::ClientInitialData:
		{
			size_t id = 0;
			packet.read(id);
			netPlayerMgr->getLocalPlayer()->setId(id);

			printf("My id: %d\n", id);

			int playersNumber = 0;

			packet.read(playersNumber);

			Vector2f pos;
			int characterType = -1;

			for (int i = 0; i < playersNumber; ++i)
			{
				packet.read(id);
				packet.read(pos.x);
				packet.read(pos.y);
				packet.read(characterType);

				auto player = netPlayerMgr->add(id);

				if (characterType != -1)
					player->changeCharacter(static_cast<Characters::Type>(characterType));

				player->updatePos(pos);

				printf("Adding player with id: %d\n", id);
			}
		} break;
		case PacketType::ClientConnected:
		{
			size_t id = 0;
			packet.read(id);

			if (id != netPlayerMgr->getLocalPlayer()->getId())
			{
				printf("Adding player with id: %d\n", id);

				netPlayerMgr->add(id);
			}
		} break;
		case PacketType::ClientDisconnected:
		{
			size_t id = 0;
			packet.read(id);
			netPlayerMgr->remove(id);

			printf("Player with id: %d disconnected!\n", id);
		} break;
		case PacketType::ClientCharacterChanged:
		{
			size_t id = 0;
			int characterType = -1;

			packet.read(id);
			packet.read(characterType);

			if (id != netPlayerMgr->getLocalPlayer()->getId())
			{
				auto player = netPlayerMgr->getPlayer(id);

				printf("Player with %d changed character type to: %d\n", id, characterType);

				if (player)
				{
					if (characterType == -1)
						player->removeCharacter();
					else
						player->changeCharacter(static_cast<Characters::Type>(characterType));
				}
			}
		} break;
		case PacketType::ClientPositionUpdate:
		{
			size_t id = 0;
			Vector2f pos;

			packet.read(id);
			packet.read(pos.x);
			packet.read(pos.y);

			if (id != netPlayerMgr->getLocalPlayer()->getId())
			{
				auto player = netPlayerMgr->getPlayer(id);

				if (player)
				{
					player->updatePos(pos);
				}
			}
		} break;
		case PacketType::ClientAnimationChanged:
		{
			size_t id = 0;

			int anim1, anim2, anim3;
			
			packet.read(id);
			packet.read(anim1);
			packet.read(anim2);
			packet.read(anim3);

			if (id != netPlayerMgr->getLocalPlayer()->getId())
			{
				auto player = netPlayerMgr->getPlayer(id);

				if (player)
				{
					auto character = player->getCharacter();

					if (character)
					{
						character->animation1 = anim1;
						character->animation2 = anim2;
						character->animation4 = anim3;
					}
				}
			}
		} break;
	}
}

void NetClient::send(NetBuffer& packet)
{
	packet.flush();
	auto enetPacket = enet_packet_create(packet.getData(), packet.getDataSize(), ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send(serverPeer, 0, enetPacket);
}
