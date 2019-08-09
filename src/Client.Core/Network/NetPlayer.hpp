/** @file NetPlayer.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include <memory>
#include <stddef.h>

#include <SMB.hpp>

#include <Shared.Types.hpp>

class NetPlayer
{
private:
	PlayerId id;
	std::unique_ptr<MeatBoyCharactor> charactor;

	Characters::Type characterType = Characters::Type::DefaultMeatBoy;

	uint64_t interptStartTime = 0;
	uint64_t interptEndTime = 0;

	Vector2f interptStartPos;
	Vector2f interptEndPos;

public:
	NetPlayer(PlayerId id);
	~NetPlayer();

	void update();
	void draw();

	void changeCharacter(Characters::Type type);
	void removeCharacter();

	void setPosition(const Vector2f& pos);

	PlayerId getId() const { return id; }
	MeatBoyCharactor* getCharacter() const { return charactor.get(); }
};