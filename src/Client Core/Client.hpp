#pragma once

#include <windows.h>

class Client
{
private:
	static HINSTANCE hInstance;

public:
	Client();
	~Client();

	static void setInstance(HINSTANCE _hInstance) { hInstance = _hInstance; }
	static HINSTANCE getInstance() { return hInstance; }
};
