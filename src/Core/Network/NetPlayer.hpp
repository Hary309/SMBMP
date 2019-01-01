#pragma once

#include <memory>

#include <SMB.hpp>

class NetPlayer
{
private:
	size_t id;
	std::unique_ptr<MeatBoyCharactor> charactor;

	Characters::Type characterType = Characters::Type::DefaultMeatBoy;

public:
	NetPlayer(size_t id);
	~NetPlayer();

	void update();
	void draw();

	void changeCharacter(Characters::Type type);
	void removeCharacter();

	void updatePos(const Vector2f& pos);

	size_t getId() const { return id; }
	MeatBoyCharactor* getCharacter() const { return charactor.get(); }
};