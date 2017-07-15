#ifndef ASTEROIDS_ASTEROID_H_
#define ASTEROIDS_ASTEROID_H_

#include <SDL.h>
#include <vector>

#include "vec2.h"

class Asteroid
{
public:
	Asteroid() {};
	Asteroid(double x, double y, float angle);
	~Asteroid();

	void Update();
	void Render(SDL_Renderer * renderer);

	Vec2 GetPosition();

private:
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;

	double angle;
};

#endif
