#include "NetServer.hpp"

#include <sstream>

#include "Network/NetPlayer.hpp"
#include "ClientManager.hpp"

NetServer::NetServer(ClientManager* clientMgr)
	: clientMgr(clientMgr)
{
}

NetServer::~NetServer()
{
	if (server)
		enet_host_destroy(server);

	enet_deinitialize();
}

bool NetServer::init(short port)
{
	if (enet_initialize() != 0)
		return false;

	ENetAddress address;
	address.host = ENET_HOST_ANY;
	address.port = port;

	server = enet_host_create(&address, 10, 2, 0, 0);

	if (!server)
		return false;

	printf("Waitng for clients...\n");

	return true;
}

void NetServer::update()
{
	ENetEvent event;

	while (enet_host_service(server, &event, 0) > 0)
	{
		switch (event.type)
		{
			case ENET_EVENT_TYPE_CONNECT:
			{
				printf("Incomming connect...\n");
			} break;
			case ENET_EVENT_TYPE_RECEIVE:
			{
				NetBuffer packet(event.packet->data, event.packet->dataLength);

				processPacket(packet, event.peer);

				enet_packet_destroy(event.packet);
			} break;
			case ENET_EVENT_TYPE_DISCONNECT:
			{
				size_t id = reinterpret_cast<NetPlayer*>(event.peer->data)->getId();

				printf("Client with id: %d lost connection!\n", id);
				clientMgr->remove(event.peer);

				NetBuffer packet(PacketType::ClientDisconnected);
				packet.write(id);
				packet.flush();
				send(packet);
			} break;
		}
	}
}

void NetServer::processPacket(NetBuffer& packet, ENetPeer* peer)
{
	switch (packet.getPacketType())
	{
		case PacketType::ClientConnected:
		{
			auto client = clientMgr->add(peer);

			printf("Client connected! Id: %d\n", client->getId());

			packet.reset(PacketType::ClientInitialData);
			packet.write(client->getId());

			packet.write(clientMgr->getSize() - 1);

			printf("Sending: %d\n", clientMgr->getSize() - 1);

			auto& clients = clientMgr->getClients();

			for (auto& _client : clients)
			{ 
				if (_client.get() == client)
					continue;

				packet.write(_client->getId());
				packet.write(_client->getPos().x);
				packet.write(_client->getPos().y);
				packet.write(_client->getCharacterType());
			}

			packet.flush();

			send(packet, peer);

			packet.reset(PacketType::ClientConnected);
			packet.write(client->getId());
			packet.flush();

			send(packet);
		} break;
		case PacketType::ClientDisconnected:
		{
			size_t id = reinterpret_cast<NetPlayer*>(peer->data)->getId();

			printf("Client with id: %d disconnected!\n", id);
			clientMgr->remove(peer);

			NetBuffer packet(PacketType::ClientDisconnected);
			packet.write(id);
			packet.flush();
			send(packet);
		} break;
		case PacketType::ClientCharacterChanged:
		{
			NetPlayer* client = reinterpret_cast<NetPlayer*>(peer->data);

			int characterType = -1;
			packet.read(characterType);

			if (characterType < 0)
				characterType = -1;
			else if (characterType > 30)
				characterType = 30;

			printf("Player %d changed charactor to: %d\n", client->getId(), characterType);

			client->setCharacterType(characterType);

			packet.reset(PacketType::ClientCharacterChanged);
			packet.write(client->getId());
			packet.write(characterType);
			packet.flush();

			send(packet);
		} break;
		case PacketType::ClientPositionUpdate:
		{
			NetPlayer* client = reinterpret_cast<NetPlayer*>(peer->data);

			Vector2f pos;

			packet.read(pos.x);
			packet.read(pos.y);

			client->setPos(pos);

			packet.reset(PacketType::ClientPositionUpdate);
			packet.write(client->getId());
			packet.write(pos.x);
			packet.write(pos.y);
			packet.flush();

			send(packet);
		} break;
		case PacketType::ClientAnimationChanged:
		{
			NetPlayer* client = reinterpret_cast<NetPlayer*>(peer->data);

			int anim1, anim2, anim3;

			packet.read(anim1);
			packet.read(anim2);
			packet.read(anim3);

			packet.reset(PacketType::ClientAnimationChanged);
			packet.write(client->getId());
			packet.write(anim1);
			packet.write(anim2);
			packet.write(anim3);
			packet.flush();

			send(packet);
		} break;
	}
}

void NetServer::send(NetBuffer& packet)
{
	auto enetPacket = enet_packet_create(packet.getData(), packet.getDataSize(), ENET_PACKET_FLAG_RELIABLE);

	for (auto& client : clientMgr->getClients())
	{
		enet_peer_send(client->getPeer(), 0, enetPacket);
	}

	enet_host_flush(server);
}

void NetServer::send(NetBuffer& packet, ENetPeer* client)
{
	auto enetPacket = enet_packet_create(packet.getData(), packet.getDataSize(), ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send(client, 0, enetPacket);
}

void NetServer::send(NetBuffer& packet, const std::vector<ENetPeer*>& peers)
{
	auto enetPacket = enet_packet_create(packet.getData(), packet.getDataSize(), ENET_PACKET_FLAG_RELIABLE);

	for (auto peer : peers)
	{
		enet_peer_send(peer, 0, enetPacket);
	}

	enet_host_flush(server);
}
