#include "asteroid.h"

#include "config.h"

Asteroid::Asteroid(double x, double y float angle)
{
	position.x = x;
	position.y = y;
	velocity.x = ASTEROID_BASE_SPEED * sin(angle * M_PI / 180.0f);
	velocity.y = ASTEROID_BASE_SPEED * -cos(angle * M_PI / 180.0f);
	acceleration = {};
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update()
{
	position.Add(velocity);
}

void Asteroid::Render(SDL_Renderer * renderer)
{
}

Vec2 Asteroid::GetPosition()
{
	return Vec2();
}
