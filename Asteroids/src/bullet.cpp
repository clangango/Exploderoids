#include "bullet.h"

#include <cmath>
#include <iostream>

#include <SDL.h>

#include "config.h"

Bullet::Bullet(double x, double y, double angle)
{
	position.x = x;
	position.y = y;
	angle = angle;
	velocity.x = BULLET_SPEED * sin(angle * M_PI / 180.0f);
	velocity.y = BULLET_SPEED * -cos(angle * M_PI / 180.0f);
	flight_time = BULLET_FLIGHT_TIME;
	start_time = SDL_GetTicks();
	hit_target = false;
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
	SDL_RenderSetScale(renderer, 2, 2);
	SDL_RenderDrawPoint(renderer, position.x / 2, position.y / 2);
	SDL_RenderSetScale(renderer, 1, 1);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

void Bullet::HitAndShouldDie()
{
	hit_target = true;
}

bool Bullet::CollidesWith(GameObject * object)
{
	return this->position.Distance(object->position) <= ASTEROID_BASE_RADIUS;
}

bool Bullet::CollidesWithAsteroid(Asteroid asteroid)
{
	//float distance = this->position.Distance(asteroid.GetPosition());
	//int size = asteroid.GetSize();
	//std::cout << distance << ', ' << size << std::endl;
	return (this->position.Distance(asteroid.position) <= (ASTEROID_BASE_RADIUS / asteroid.GetSize()));
}

bool Bullet::ShouldEnd()
{
	return ((SDL_GetTicks() - start_time) > flight_time) || hit_target;
}
