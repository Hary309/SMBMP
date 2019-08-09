#pragma once

#include <stddef.h>

#include <SMB.hpp>

#include <Shared.Types.hpp>

class NetClientPlayer
{
private:
	PlayerId id = 0;
	MeatBoyCharactor** player = nullptr;

	MeatBoyCharactor* recentPlayerPtr = nullptr;

	uint64_t recentPositionUpdateTime = 0;

public:
	NetClientPlayer();
	~NetClientPlayer();

	void update();

	void setId(PlayerId _id) { id = _id; }
	PlayerId getId() const { return id; }

	MeatBoyCharactor* getPlayer() const { return *player; }
};