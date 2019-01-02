#pragma once

#include <enet/enet.h>

#include <Types.hpp>
#include <Vector2.hpp>

class NetPlayer
{
private:
	PlayerId id = 0;
	ENetPeer* peer = nullptr;
	
	int characterType = -1;
	Vector2f pos;

public:
	NetPlayer(PlayerId id, ENetPeer* peer)
		: id(id), peer(peer)
	{
	}

	void setPos(const Vector2f& pos) { this->pos = pos; }
	const Vector2f& getPos() const { return pos; }
	
	void setCharacterType(int characterType) { this->characterType = characterType; }
	int getCharacterType() const { return characterType; }

	PlayerId getId() const { return id; }
	ENetPeer* getPeer() const { return peer; }
};