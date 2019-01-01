#pragma once

#include <stddef.h>

#include <SMB.hpp>

class NetClientPlayer
{
private:
	size_t id = 0;
	MeatBoyCharactor** player = nullptr;

	MeatBoyCharactor* recentPlayerPtr = nullptr;

	uint32_t recentPositionUpdateTime;

public:
	NetClientPlayer();
	~NetClientPlayer();

	void update();

	void setId(size_t _id) { id = _id; }
	size_t getId() const { return id; }

	MeatBoyCharactor* getPlayer() const { return *player; }
};