#pragma once

#include "Buffer.hpp"

enum class PacketType
{
	ClientConnected,
	ClientInitialData,
	ClientDisconnected,

	ClientCharacterChanged,
	ClientPositionUpdate
};
