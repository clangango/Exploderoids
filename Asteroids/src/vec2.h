#ifndef ASTEROIDS_VEC2_H_
#define ASTEROIDS_VEC2_H_

#include <cmath>

struct Vec2
{
	double x, y;

	Vec2(double x = 0.0, double y = 0.0)
		: x(x), y(y) {}

	Vec2 & Add(const Vec2 & other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	float Magnitude()
	{
		return sqrt(x * x + y * y);
	}
};

#endif