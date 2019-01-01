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
				printf("%p disconnected.\n", event.peer);

				clientMgr->remove(event.peer);
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
			packet.flush();

			send(packet, peer);

			packet.reset(PacketType::ClientConnected);
			packet.write(client->getId());
			packet.flush();

			send(packet);
		} break;
		case PacketType::ClientDisconnected:
		{
			printf("Client disconnected!");

			clientMgr->remove(peer);
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

			packet.read(x);
			packet.read(y);

			packet.reset(PacketType::ClientPositionUpdate);
			packet.write(client->getId());
			packet.write(pos.x);
			packet.write(pos.y);
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
