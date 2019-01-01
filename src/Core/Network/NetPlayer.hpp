#pragma once

#include <memory>
#include <stddef.h>

#include <SMB.hpp>

class NetPlayer
{
private:
	size_t id;
	std::unique_ptr<MeatBoyCharactor> charactor;

	Characters::Type characterType = Characters::Type::DefaultMeatBoy;

	uint32_t interptStartTime;
	uint32_t interptEndTime;

	Vector2f interptStatPos;
	Vector2f interptEndPos;

public:
	NetPlayer(size_t id);
	~NetPlayer();

	void update();
	void draw();

	void changeCharacter(Characters::Type type);
	void removeCharacter();

	void setPosition(const Vector2f& pos);

	size_t getId() const { return id; }
	MeatBoyCharactor* getCharacter() const { return charactor.get(); }
};