#include "Timing.h"


namespace WolfEngine
{
	Timing::Timing()
	{
	}

	Timing::~Timing()
	{
	}

	void Timing::init(float maxFPS) {
		setMaxFPS(maxFPS);
	}

	void Timing::setMaxFPS(float maxFPS) {
		_maxFPS = maxFPS;
	}

	void Timing::begin() {
		_startTicks = SDL_GetTicks();
	}

	float Timing::end() {
		calculateFPS();

		float frameTicks = SDL_GetTicks() - _startTicks;
		if (1000.0f / _maxFPS > frameTicks) {
			SDL_Delay((Uint32)(1000.0f / _maxFPS - frameTicks));
		}

		return _fps;
	}

	void Timing::calculateFPS() {
		static const int NUM_SAMPLES = 10;
		static float frameTimes[NUM_SAMPLES];
		static int currentFrame = 0;
		static float prevTicks = SDL_GetTicks();

		float currentTicks = SDL_GetTicks();

		_frameTime = currentTicks - prevTicks;
		frameTimes[currentFrame % NUM_SAMPLES] = _frameTime;

		prevTicks = currentTicks;

		int count;

		currentFrame++;
		if (currentFrame < NUM_SAMPLES) {
			count = currentFrame;
		}
		else {
			count = NUM_SAMPLES;
		}

		float frameTimeAverage = 0;
		for (int i = 0; i < count; i++) {
			frameTimeAverage += frameTimes[i];
		}
		frameTimeAverage /= count;

		if (frameTimeAverage > 0) {
			_fps = 1000.0f / frameTimeAverage;
		}
		else {
			_fps = 60.0f;
		}
	}
}

