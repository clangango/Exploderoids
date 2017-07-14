#include "timer.h"

Timer::Timer()
{
	Reset();
	time_scale_ = 1.0f;
}

Timer::~Timer()
{
	time_scale_ = NULL;
}

void Timer::Update()
{
	elapsed_time_ = SDL_GetTicks() - start_ticks_;
	delta_time_ = elapsed_time_ * 0.001f;
}

void Timer::Reset()
{
	start_ticks_ = SDL_GetTicks();
	elapsed_time_ = 0;
	delta_time_ = 0.0f;
}

void Timer::SetTimeScale(float t)
{
	time_scale_ = t;
}

float Timer::GetTimeScale()
{
	return time_scale_;
}

float Timer::GetDeltaTime()
{
	return delta_time_;;
}
