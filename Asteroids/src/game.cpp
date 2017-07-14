#include "game.h"

#include <iostream>

#include "config.h"

Game::Game()
{
	running_ = Init();
	player = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
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
		if(timer_->GetDeltaTime() >= 1.0f / FRAMES_PER_SECOND)
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
	while(SDL_PollEvent(&event_))
	{
		switch(event_.type)
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
}

void Game::LateUpdate()
{
	timer_->Reset();
}

void Game::Render()
{
	window_->Clear();
	player.Render(window_->GetRenderer());
	window_->Present();
}
