#pragma once

#include <WinSock2.h>

#include <memory>
#include <windows.h>

class NetClient;
class NetPlayerManager;

class Client
{
private:
	static Client* instance;

private:
	std::unique_ptr<NetClient> netClient;
	std::unique_ptr<NetPlayerManager> netPlayerMgr;
	HINSTANCE hInstance;

public:
	Client(HINSTANCE _hInstance);
	~Client();

	void init();
	void shutdown();

	void update();
	void draw_playerLayer();

	NetClient* getNetClient() { return netClient.get(); }
	NetPlayerManager* getPlayerMgr() { return netPlayerMgr.get(); }

	HINSTANCE getHInstance() { return hInstance; }

	static Client* get() { return instance; }
};
