#include "window.h"

Window::Window()
{
	Init();
}

Window::~Window()
{
}

void Window::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		std::cout << "SDL initialization error: " << SDL_GetError();
	}

	window_ = SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 900, 700, SDL_WINDOW_SHOWN);

	if (window_ == NULL)
	{
		std::cout << "Window creation error: " << SDL_GetError();
	}

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

	if (renderer_ == NULL)
	{
		std::cout << "Renderer creation error: " << SDL_GetError();
	}

	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
}

void Window::Clear()
{
	SDL_RenderClear(renderer_);
}

void Window::Present()
{
	SDL_RenderPresent(renderer_);
}

void Window::Clean()
{
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();

	renderer_ = nullptr;
	window_ = nullptr;
}

SDL_Renderer * Window::GetRenderer()
{
	return renderer_;
}
