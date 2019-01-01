#pragma once

template<typename T>
class Vector2
{
public:
	T x;
	T y;

public:
	Vector2()
		: x(), y()
	{
	}

	Vector2(T X, T Y)
		: x(X), y(Y)
	{
	}

	constexpr Vector2<T> operator+(const Vector2<T>& other)
	{
		Vector2 result;
		result.x = x + other.x;
		result.y = y + other.y;
		return (*this);
	}

	constexpr Vector2<T>& operator+=(const Vector2<T>& other)
	{
		x += other.x;
		y += other.y;
		return (*this);
	}

	constexpr Vector2<T> operator-(const Vector2<T>& other)
	{
		Vector2<T> result;
		result.x = x - other.x;
		result.y = y - other.y;
		return result;
	}

	constexpr Vector2<T>& operator-=(const Vector2<T>& other)
	{
		x -= other.x;
		y -= other.y;
		return (*this);
	}

	constexpr Vector2<T> operator*(const Vector2<T>& other)
	{
		Vector2 result;
		result.x = x * other.x;
		result.y = y * other.y;
		return result;
	}

	constexpr Vector2<T>& operator*=(const Vector2<T>& other)
	{
		x *= other.x;
		y *= other.y;
		return (*this);
	}

	constexpr Vector2<T> operator*(float value)
	{
		Vector2<T> result;
		result.x = this->x * value;
		result.y = this->y * value;
		return result;
	}

	constexpr Vector2<T>& operator*=(float value)
	{
		x *= value;
		y *= value;
		return (*this);
	}
};


using Vector2f = Vector2<float>;
