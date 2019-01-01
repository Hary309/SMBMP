#include "NetPlayer.hpp"

NetPlayer::NetPlayer(size_t id)
	: id(id)
{
}

NetPlayer::~NetPlayer()
{
}

void NetPlayer::update()
{

}

void NetPlayer::draw()
{
	if (charactor)
	{
		charactor->draw();
	}
}

void NetPlayer::removeCharacter()
{
	charactor.reset();
}

void NetPlayer::updatePos(const Vector2& pos)
{
	if (charactor)
	{
		charactor->setPosition(pos);
	}
}

void NetPlayer::changeCharacter(Characters::Type type)
{
	characterType = type;

	charactor = std::unique_ptr<MeatBoyCharactor>(MeatBoyCharactor::createCharacter(type));
}
