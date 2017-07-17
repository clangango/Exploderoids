#ifndef ASTEROIDS_GAMEOBJECT_H_
#define ASTEROIDS_GAMEOBJECT_H_

#include <SDL.h>

#include "vec2.h"

class GameObject
{
public:
	GameObject() {};
	virtual ~GameObject() {};
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer * renderer) = 0;

	//Vec2 GetPosition() { return position };

	virtual bool CollidesWith(GameObject * object) = 0;

	Vec2 position;

protected:
	Vec2 velocity;
	Vec2 acceleration;

	double angle;
};

#endif