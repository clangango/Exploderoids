#include "asteroid.h"

#include <iostream>

#include "config.h"

Asteroid::Asteroid(double x, double y, double angle, int size)
{
	position.x = x;
	position.y = y;
	angle = angle;
	acceleration = { 0.0, 0.0 };
	this->size = size;
	velocity.x = ASTEROID_BASE_SPEED * size * 0.5 * sin(angle * M_PI / 180.0f);
	velocity.y = ASTEROID_BASE_SPEED * size * 0.5 * -cos(angle * M_PI / 180.0f);
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update()
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

void Asteroid::Render(SDL_Renderer * renderer)
{
	double x1 = position.x - (30.0 * 1 / size);
	double y1 = position.y + (0.0 * 1 / size);
	double x2 = position.x - (10.0 * 1 / size);
	double y2 = position.y - (25.0 * 1 / size);
	double x3 = position.x + (0.0 * 1 / size);
	double y3 = position.y - (30.0 * 1 / size);
	double x4 = position.x + (25.0 * 1 / size);
	double y4 = position.y - (20.0 * 1 / size);
	double x5 = position.x + (30.0 * 1 / size);
	double y5 = position.y + (0.0 * 1 / size);
	double x6 = position.x + (20.0 * 1 / size);
	double y6 = position.y + (20.0 * 1 / size);
	double x7 = position.x + (0.0 * 1 / size);
	double y7 = position.y + (30.0 * 1 / size);
	double x8 = position.x - (25.0 * 1 / size);
	double y8 = position.y + (25.0 * 1 / size);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
	SDL_RenderDrawLine(renderer, x3, y3, x4, y4);
	SDL_RenderDrawLine(renderer, x4, y4, x5, y5);
	SDL_RenderDrawLine(renderer, x5, y5, x6, y6);
	SDL_RenderDrawLine(renderer, x6, y6, x7, y7);
	SDL_RenderDrawLine(renderer, x7, y7, x8, y8);
	SDL_RenderDrawLine(renderer, x8, y8, x1, y1);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

bool Asteroid::CollidesWith(GameObject * object)
{
	return false;
}

int Asteroid::GetSize()
{
	return size;
}
