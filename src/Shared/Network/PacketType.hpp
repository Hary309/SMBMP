/** @file PacketType.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

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

