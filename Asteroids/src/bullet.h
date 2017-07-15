#ifndef ASTEROIDS_BULLET_H_
#define ASTEROIDS_BULLET_H_

#include <SDL.h>

#include "vec2.h"

class Bullet
{
public:
	Bullet() {};
	Bullet(double x, double y, double angle);
	~Bullet();

	void Update();
	void Render(SDL_Renderer * renderer);

	Vec2 GetPosition();

	bool ShouldEnd();

private:
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;

	double angle;
	unsigned int flight_time;
	unsigned int start_time;
};

#endif