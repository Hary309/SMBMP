#pragma once

#include <algorithm>

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

	static Vector2<T> lerp(const Vector2<T>& a, const Vector2<T>& b, float alpha)
	{
		alpha = std::clamp(alpha, 0.f, 1.f);

		Vector2<T> result;
		result.x = (b.x - a.x) * alpha;
		result.y = (b.y - a.y) * alpha;
		return result;
	}
};

template <typename T>
constexpr Vector2<T> operator -(const Vector2<T>& right)
{
	return Vector2<T>(-right.x, -right.y);
}

template <typename T>
constexpr Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right)
{
	left.x += right.x;
	left.y += right.y;

	return left;
}

template <typename T>
constexpr Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right)
{
	left.x -= right.x;
	left.y -= right.y;

	return left;
}

template <typename T>
constexpr Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right)
{
	return Vector2<T>(left.x + right.x, left.y + right.y);
}

template <typename T>
constexpr Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right)
{
	return Vector2<T>(left.x - right.x, left.y - right.y);
}

template <typename T>
constexpr Vector2<T> operator *(const Vector2<T>& left, T right)
{
	return Vector2<T>(right.x * left, right.y * left);
}

template <typename T>
constexpr Vector2<T> operator *(T left, const Vector2<T>& right)
{
	return Vector2<T>(left.x * right, left.y * right);
}

template <typename T>
constexpr Vector2<T>& operator *=(Vector2<T>& left, T right)
{
	left.x *= right;
	left.y *= right;

	return left;
}

template <typename T>
constexpr Vector2<T> operator /(const Vector2<T>& left, T right)
{
	return Vector2<T>(left.x / right, left.y / right);
}

template <typename T>
constexpr Vector2<T>& operator /=(Vector2<T>& left, T right)
{
	left.x /= right;
	left.y /= right;

	return left;
}

using Vector2f = Vector2<float>;
