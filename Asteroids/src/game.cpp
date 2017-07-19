#include "game.h"

#include <iostream>

#include "config.h"

Game::Game()
{
	running_ = Init();
	player = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };

	asteroids.push_back(Asteroid{ 100, 200,  60, ASTEROID_SIZE::LARGE });
	asteroids.push_back(Asteroid{ 50,  600, 160, ASTEROID_SIZE::LARGE });
	asteroids.push_back(Asteroid{ 800, 100,  30, ASTEROID_SIZE::LARGE });
	asteroids.push_back(Asteroid{ 850, 500, 248, ASTEROID_SIZE::LARGE });
}

Game::~Game()
{
	delete window_;
	delete timer_;

	window_ = nullptr;
	timer_ = nullptr;
}

bool Game::Init()
{
	timer_ = new Timer();
	window_ = new Window();
	return true;
}

void Game::Run()
{
	while (running_)
	{
		timer_->Update();
		if (timer_->GetDeltaTime() >= 1.0f / FRAMES_PER_SECOND)
		{
			EarlyUpdate();
			Update();
			LateUpdate();
			Render();
		}
	}

	window_->Clean();
}

void Game::HandleInput()
{
	while (SDL_PollEvent(&event_))
	{
		switch (event_.type)
		{
		case SDL_QUIT:
			running_ = false;
			break;
		case SDL_KEYDOWN:
			if (event_.key.keysym.sym == SDLK_UP)
				player.thrust_ = true;
			if (event_.key.keysym.sym == SDLK_LEFT)
				player.rotate_left_ = true;
			if (event_.key.keysym.sym == SDLK_RIGHT)
				player.rotate_right_ = true;
			if (event_.key.keysym.sym == SDLK_SPACE)
			{
				if (player.Fire())
				{
					bullets.push_back(Bullet{ player.GetPosition().x, 
						player.GetPosition().y, player.GetAngle() });
				}
			}
			break;
		case SDL_KEYUP:
			if (event_.key.keysym.sym == SDLK_UP)
				player.thrust_ = false;
			if (event_.key.keysym.sym == SDLK_LEFT)
				player.rotate_left_ = false;
			if (event_.key.keysym.sym == SDLK_RIGHT)
				player.rotate_right_ = false;
			break;
		}
	}
}

void Game::EarlyUpdate()
{
	HandleInput();
}

void Game::Update()
{
	player.Update();

	std::vector<Bullet>::iterator it = bullets.begin();
	while (it != bullets.end())
	{
		if (it->ShouldEnd())
			it = bullets.erase(it);
		else
		{
			it->Update();
			++it;
		}
	}

	for (unsigned int i = 0; i < asteroids.size(); i++)
	{
		asteroids[i].Update();
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < asteroids.size(); j++)
		{
			if (bullets[i].CollidesWith(&asteroids[j]))
			{
				if (asteroids[j].GetSize() < 3)
				{
					asteroids.push_back(Asteroid{ asteroids[j].position.x, asteroids[j].position.y, 45.0, asteroids[j].GetSize() + 1 });
					asteroids.push_back(Asteroid{ asteroids[j].position.x, asteroids[j].position.y, 135.0, asteroids[j].GetSize() + 1 });
					asteroids.erase(asteroids.begin() + j);
				}
				else
				{
					asteroids.erase(asteroids.begin() + j);
				}
				bullets[i].HitAndShouldDie();
			}
		}
	}

	for (int i = 0; i < asteroids.size(); i++)
	{
		if (player.CollidesWith(&asteroids[i]))
		{
			std::cout << "Ouch" << std::endl;
			asteroids.erase(asteroids.begin() + i);
			break;
		}
	}
}

void Game::LateUpdate()
{
	timer_->Reset();
}

void Game::Render()
{
	window_->Clear();
	player.Render(window_->GetRenderer());

	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		bullets[i].Render(window_->GetRenderer());
	}

	for (unsigned int i = 0; i < asteroids.size(); i++)
	{
		asteroids[i].Render(window_->GetRenderer());
	}

	window_->Present();
}
