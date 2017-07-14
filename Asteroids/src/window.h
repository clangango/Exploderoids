#ifndef ASTEROIDS_WINDOW_H_
#define ASTEROIDS_WINDOW_H_

#include <iostream>

#include <SDL.h>

class Window
{
public:
	Window();
	~Window();
	void Init();
	void Clear();
	void Present();
	void Clean();

	SDL_Renderer * GetRenderer();

private:
	SDL_Window * window_;
	SDL_Renderer * renderer_;
};
#endif
