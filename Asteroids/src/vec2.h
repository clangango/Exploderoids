#ifndef ASTEROIDS_VEC2_H_
#define ASTEROIDS_VEC2_H_

#pragma warning (disable : 4244)

#include <cmath>

struct Vec2
{
	double x, y;

	Vec2() 
		: x(0.0), y(0.0)
	{}
	Vec2(double x, double y)
		: x(x), y(y) {}

	Vec2 & Add(const Vec2 & other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vec2 & Subtract(const Vec2 & other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vec2 & Multiply(const float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	float Magnitude()
	{
		return sqrt(x * x + y * y);
	}

	float Distance(const Vec2 & other)
	{
		double dx = x - other.x;
		double dy = y - other.y;
		return sqrt(dx * dx + dy * dy);
	}
};

#endif