#include "player.h"

#include <iostream>
#include <cmath>

#include "config.h"

Player::Player(double x, double y)
{
	position = { x, y };
	velocity = {};
	acceleration = {};
	angle = 0.0;
	thrust_ = false;
	rotate_left_ = false;
	rotate_right_ = false;
}

Player::~Player()
{
}

void Player::RotateRight()
{
	angle += PLAYER_ROTATION_AMOUNT;
}

void Player::RotateLeft()
{
	angle -= PLAYER_ROTATION_AMOUNT;
}

void Player::Thrust()
{
	acceleration.x = 5.0 * sin(angle * (M_PI / 180.0f));
	acceleration.y = 5.0 * -cos(angle * (M_PI / 180.0f));
}

void Player::Fire()
{
}

void Player::Update()
{
	if (thrust_)
		Thrust();
	if (!thrust_)
	{
		acceleration.x = 0.0;
		acceleration.y = 0.0;
		velocity.x *= 0.975;
		velocity.y *= 0.975;
	}
	if (rotate_left_)
		RotateLeft();
	if (rotate_right_)
		RotateRight();
	velocity.Add(acceleration);
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

void Player::Render(SDL_Renderer * renderer)
{
	float theta = angle * M_PI / 180.0f;

	float cs = cos(theta);
	float sn = sin(theta);

	double x1 = -8 * cs - 15 * sn;
	double y1 = -8 * sn + 15 * cs;
	double x2 = 0 * cs + 15 * sn;
	double y2 = 0 * sn - 15 * cs;
	double x3 = 8 * cs - 15 * sn;
	double y3 = 8 * sn + 15 * cs;
	double x4 = 0 * cs - 8 * sn;
	double y4 = 0 * sn + 8 * cs;

	x1 += position.x;
	y1 += position.y;
	x2 += position.x;
	y2 += position.y;
	x3 += position.x;
	y3 += position.y;
	x4 += position.x;
	y4 += position.y;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
	SDL_RenderDrawLine(renderer, x3, y3, x4, y4);
	SDL_RenderDrawLine(renderer, x4, y4, x1, y1);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

Vec2 Player::GetPosition()
{
	return position;
}
