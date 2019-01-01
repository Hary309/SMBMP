#pragma once

#include <string>
#include <string_view>
#include <cstdint>
#include <type_traits>

class Buffer
{
public:
	constexpr static int MAX_PACKET_SIZE = 64;

private:
	size_t dataPointer = 0;
	size_t dataSize = 0;

	uint8_t data[MAX_PACKET_SIZE] = { 0 };

private:
	template <size_t Offset, typename T>
	void writeByte(T value)
	{
		using RefArray_t = char[sizeof(T)];

		data[dataPointer++] = (reinterpret_cast<RefArray_t&>(value)[Offset] & 0xFF);
	}

	template<typename T, size_t... Is>
	void writeBytes(T value, std::index_sequence<Is...>)
	{
		(writeByte<Is>(value), ...);
	}

	template<size_t Offset, typename T>
	void readByte(T& value)
	{
		using RefArray_t = char[sizeof(T)];

		(reinterpret_cast<RefArray_t&>(value)[Offset]) = data[dataPointer++];
	}

	template<typename T, size_t... Is>
	void readBytes(T& value, std::index_sequence<Is...>)
	{
		(readByte<Is>(value), ...);
	}

public:
	Buffer() = default;

	Buffer(uint8_t* data, size_t size)
		: dataPointer(0), dataSize(size)
	{
		memcpy(this->data, data, size);
	}

	~Buffer() = default;

	template<typename T>
	void write(const T& value)
	{
		static_assert(std::is_fundamental_v<T>, "Only primitive types");

		constexpr size_t typeSize = sizeof(T);

		if (typeSize + dataPointer >= MAX_PACKET_SIZE)
			return;

		writeBytes(value, std::make_index_sequence<typeSize>());
	}

	template<>
	void write<std::string>(const std::string& str)
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			data[dataPointer++] = static_cast<char>(str[i]);
		}

		data[dataPointer++] = '\0';
	}

	void flush()
	{
		dataSize = dataPointer;
		dataPointer = 0;
	}

	template<typename T>
	void read(T& value)
	{
		static_assert(std::is_fundamental_v<T>, "Only primitive types");

		constexpr size_t typeSize = sizeof(T);

		if (dataPointer - typeSize < 0)
			return;

		readBytes(value, std::make_index_sequence<typeSize>());
	}

	template <>
	void read<std::string>(std::string& str)
	{
		while (data[dataPointer] != '\0') 
		{
			str += data[dataPointer];

			dataPointer++;
		}

		// skip Null-terminated (zero)
		dataPointer++;
	}

	size_t getDataSize() const { return dataSize; }

	auto getData() const { return data; }

	void reset()
	{
		dataPointer = 0;
		dataSize = 0;

		memset(data, 0, MAX_PACKET_SIZE);
	}

	void print(int start = 0, int end = MAX_PACKET_SIZE)
	{
		for (int i = start; i < end; i++)
		{
			printf("%X ", data[i]);
		}

		printf("\n");
	}
};
