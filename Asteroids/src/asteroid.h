#ifndef ASTEROIDS_ASTEROID_H_
#define ASTEROIDS_ASTEROID_H_

#include <SDL.h>
#include <vector>

#include "vec2.h"
#include "game_object.h"

class Asteroid : public GameObject
{
public:
	Asteroid() {};
	Asteroid(double x, double y, double angle, int size);
	~Asteroid();

	void Update();
	void Render(SDL_Renderer * renderer);
	bool CollidesWith(GameObject * object);

	int GetSize();

private:
	int size;
};

#endif
