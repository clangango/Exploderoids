#ifndef ASTEROIDS_BULLET_H_
#define ASTEROIDS_BULLET_H_

#include <SDL.h>

#include "game_object.h"
#include "vec2.h"
#include "asteroid.h"

class Bullet : public GameObject
{
public:
	Bullet() {};
	Bullet(double x, double y, double angle);
	~Bullet();

	void Update();
	void Render(SDL_Renderer * renderer);
	void HitAndShouldDie();

	bool ShouldEnd();
	bool CollidesWith(GameObject * object);
	bool CollidesWithAsteroid(Asteroid asteroid);

private:
	unsigned int flight_time;
	unsigned int start_time;
	bool hit_target;
};

#endif