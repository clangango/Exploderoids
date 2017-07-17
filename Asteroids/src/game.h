#ifndef _ASTEROIDS_GAME_H_
#define _ASTEROIDS_GAME_H_

#include <vector>

#include "window.h"
#include "timer.h"
#include "player.h"
#include "bullet.h"
#include "asteroid.h"
#include "game_object.h"

class Game
{
public:
	Game();
	~Game();
	bool Init();
	void Run();
	void HandleInput();
	void EarlyUpdate();
	void Update();
	void LateUpdate();
	void Render();

private:
	SDL_Event event_;
	Window * window_;
	bool running_;
	Timer * timer_;

	Player player;

	std::vector<Bullet> bullets;
	std::vector<Asteroid> asteroids;
};

#endif