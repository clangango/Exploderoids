#ifndef ASTEROIDS_PLAYER_H_
#define ASTEROIDS_PLAYER_H_

#include <SDL.h>
#include <vector>

#include "vec2.h"
#include "bullet.h"

class Player
{
public:
	Player() {};
	Player(double x, double y);
	~Player();

	void RotateRight();
	void RotateLeft();
	void Thrust();
	bool Fire();

	void Update();
	void Render(SDL_Renderer * renderer);

	Vec2 GetPosition();
	float GetAngle();

	bool thrust_;
	bool rotate_right_;
	bool rotate_left_;

private:
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;

	double angle;

	int time_last_fired_;
};

#endif
