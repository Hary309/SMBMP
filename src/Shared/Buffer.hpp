/** @file Buffer.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include <string>
#include <type_traits>
#include <utility>
#include <cstring>
#include <cstdint>

namespace detail
{
	template<typename T>
	inline uint32_t write(const T& value, uint8_t* data)
	{
		constexpr size_t typeSize = sizeof(T);

		memcpy(data, &value, typeSize);

		return typeSize;
	}

	template<>
	inline uint32_t write<std::string>(const std::string& str, uint8_t* data)
	{
		return static_cast<uint32_t>(str.copy(static_cast<char*>(static_cast<void*>(data)), str.length())) + 1;
	}

	template<typename T>
	inline uint32_t read(T& value, uint8_t* data)
	{
		constexpr size_t typeSize = sizeof(T);

		memcpy(&value, data, typeSize);

		return typeSize;
	}

	template <>
	inline uint32_t read<std::string>(std::string& str, uint8_t* data)
	{
		str = std::string(static_cast<const char*>(static_cast<void*>(data)));

		return static_cast<uint32_t>(str.length() + 1);
	}
}

class Buffer
{
public:
	constexpr static int MAX_PACKET_SIZE = 64;

private:
	uint32_t dataPointer = 0;
	uint32_t dataSize = 0;

	uint8_t data[MAX_PACKET_SIZE] = { 0 };

public:
	Buffer() = default;

	Buffer(uint8_t* data, uint32_t size)
		: dataPointer(0), dataSize(size)
	{
		memcpy(this->data, data, size);
	}

	~Buffer() = default;


	template<typename T>
	void write(const T& value)
	{
		dataPointer += detail::write<T>(value, &data[dataPointer]);
	}

	template<typename T>
	void read(T& value)
	{
		dataPointer += detail::read<T>(value, &data[dataPointer]);
	}

	void flush()
	{
		dataSize = dataPointer;
		dataPointer = 0;
	}

	uint32_t getDataSize() const { return dataSize; }

	auto getData() const { return data; }

	void reset()
	{
		dataPointer = 0;
		dataSize = 0;

		memset(data, 0, MAX_PACKET_SIZE);
	}

	void printBytes(int start = 0, int end = MAX_PACKET_SIZE)
	{
		for (int i = start; i < end; i++)
		{
			printf("%02X ", data[i]);
		}

		printf("\n");
	}
};
