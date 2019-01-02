#include "NetPlayer.hpp"

#include "NetClient.hpp"

NetPlayer::NetPlayer(PlayerId id)
	: id(id)
{
}

NetPlayer::~NetPlayer()
{
}

void NetPlayer::update()
{
	if (charactor)
	{
		float alpha = float(GetTickCount() - interptStartTime) / (1000 / NetClient::TickRate);

		auto lerp = Vector2f::lerp(interptStatPos, interptEndPos, alpha);

		charactor->setPosition(interptStatPos + lerp);
	}
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

void NetPlayer::setPosition(const Vector2f& pos)
{
	if (charactor)
	{
		interptStartTime = GetTickCount();
		interptStatPos = interptEndPos;
		interptEndPos = pos;
	}
}

void NetPlayer::changeCharacter(Characters::Type type)
{
	characterType = type;

	charactor = std::unique_ptr<MeatBoyCharactor>(MeatBoyCharactor::createCharacter(type));
}
