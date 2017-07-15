#include "bullet.h"

#include <cmath>

#include <SDL.h>

#include "config.h"

Bullet::Bullet(double x, double y, double angle)
{
	position = { x, y };
	velocity.x = BULLET_SPEED * sin(angle * M_PI / 180.0f);
	velocity.y = BULLET_SPEED * -cos(angle * M_PI / 180.0f);
	acceleration = {};
	flight_time = BULLET_FLIGHT_TIME;
	start_time = SDL_GetTicks();
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	position.Add(velocity);

	if (position.y < 0.0)
		position.y = SCREEN_HEIGHT;
	if (position.y > SCREEN_HEIGHT)
		position.y = 0.0;
	if (position.x < 0.0)
		position.x = SCREEN_WIDTH;
	if (position.x > SCREEN_WIDTH)
		position.x = 0.0;
}

void Bullet::Render(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawPoint(renderer, position.x, position.y);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

Vec2 Bullet::GetPosition()
{
	return Vec2();
}

bool Bullet::ShouldEnd()
{
	return (SDL_GetTicks() - start_time) > flight_time;
}
