#pragma once

#include <chrono>

#include <SMB.hpp>

class NetClientPlayer
{
private:
	using time_point = std::chrono::steady_clock::time_point;

private:
	size_t id = 0;
	MeatBoyCharactor** player = nullptr;

	MeatBoyCharactor* recentPlayerPtr = nullptr;

	time_point recentPositionUpdateTime;

public:
	NetClientPlayer();
	~NetClientPlayer();

	void update();

	void setId(size_t _id) { id = _id; }
	size_t getId() const { return id; }

	MeatBoyCharactor* getPlayer() const { return *player; }
};