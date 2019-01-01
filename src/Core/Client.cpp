#include "Client.hpp"

#include <Memory/Offsets.hpp>
#include <Hooks/Hooks.hpp>

#include <SMB.hpp>

#include "Network/NetClient.hpp"
#include "Network/NetPlayerManager.hpp"

Client* Client::instance;

Client::Client(HINSTANCE hInstance)
{
	printf("Initalizing core...\n");

	instance = this;
	Client::hInstance = hInstance;

	Offsets::init();
	GameOffsets::init();
	Hooks::init();
}

Client::~Client()
{
}

void Client::init()
{
	printf("Initalizing...\n");

	netPlayerMgr = std::make_unique<NetPlayerManager>();
	netClient = std::make_unique<NetClient>(netPlayerMgr.get());

	netClient->connect("127.0.0.1", 1234);
}

void Client::update()
{
	if (netPlayerMgr)
		netPlayerMgr->update();

	if (netClient)
		netClient->update();
}

void Client::draw_playerLayer()
{
	if (netPlayerMgr)
		netPlayerMgr->draw_playerLayer();
}
