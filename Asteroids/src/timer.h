#ifndef ASTEROIDS_TIMIER_H_
#define ASTEROIDS_TIMER_H_

#include <SDL.h>

class Timer
{
public:
	Timer();
	~Timer();

	void Update();
	void Reset();
	void SetTimeScale(float t);

	float GetTimeScale();
	float GetDeltaTime();

private:
	unsigned int start_ticks_;
	unsigned int elapsed_time_;
	float delta_time_;
	float time_scale_;
};

#endif
