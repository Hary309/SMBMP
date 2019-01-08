#pragma once

#include "Buffer.hpp"

enum class PacketType
{
	// game
	ClientConnected,
	ClientInitialData,
	ClientDisconnected,

	ClientCharacterChanged,
	ClientPositionUpdate,
	ClientAnimationChanged,


	// master server
	AddServer,

	RequestServersList,
	RequestServerAddress,

	ServerAddress
};

