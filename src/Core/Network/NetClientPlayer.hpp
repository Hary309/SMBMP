#pragma once

#include <stddef.h>

#include <SMB.hpp>

#include <Types.hpp>

class NetClientPlayer
{
private:
	PlayerId id = 0;
	MeatBoyCharactor** player = nullptr;

	MeatBoyCharactor* recentPlayerPtr = nullptr;

	uint32_t recentPositionUpdateTime;

public:
	NetClientPlayer();
	~NetClientPlayer();

	void update();

	void setId(PlayerId _id) { id = _id; }
	PlayerId getId() const { return id; }

	MeatBoyCharactor* getPlayer() const { return *player; }
};