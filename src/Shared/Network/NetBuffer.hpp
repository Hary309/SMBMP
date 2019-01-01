#pragma once

#include "Buffer.hpp"
#include "PacketType.hpp"

class NetBuffer : public Buffer
{
	PacketType packetType;

public:
	NetBuffer(PacketType packetType)
		: packetType(packetType)
	{
		write(static_cast<int>(packetType));
	}

	NetBuffer(uint8_t* data, size_t size)
		: Buffer(data, size)
	{
		int _packetType = 0;
		read(_packetType);
		packetType = static_cast<PacketType>(_packetType);
	}

	void reset(PacketType packetType)
	{
		Buffer::reset();

		this->packetType = packetType;

		write(static_cast<int>(packetType));
	}

	PacketType getPacketType() const { return packetType; }
};