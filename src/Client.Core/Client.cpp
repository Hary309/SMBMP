/** @file Client.cpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#include "Client.hpp"

#include <SMB/Offsets.hpp>
#include <Hooks/Hooks.hpp>

#include <SMB.hpp>

#include <Shared.Network.hpp>

#include "Network/NetClient.hpp"
#include "Network/NetPlayerManager.hpp"

Client* Client::instance;

Client::Client(HINSTANCE hInstance)
{
	printf("Initalizing core...\n");

	instance = this;
	Client::hInstance = hInstance;

	Offsets::init();
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

	netClient->connect("127.0.0.1", ServerPort);
}

void Client::shutdown()
{
	printf("Shutting down...\n");

	netClient.reset();
	netPlayerMgr.reset();
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
