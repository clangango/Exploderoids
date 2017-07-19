#ifndef ASTEROIDS_PLAYER_H_
#define ASTEROIDS_PLAYER_H_

#include <SDL.h>
#include <vector>

#include "vec2.h"
#include "game_object.h"

class Player : public GameObject
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

	bool CollidesWith(GameObject * object);

	bool thrust_;
	bool rotate_right_;
	bool rotate_left_;

private:
	int time_last_fired_;
};

#endif
