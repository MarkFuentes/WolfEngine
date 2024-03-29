#pragma once
#include <SDL/SDL.h>
namespace WolfEngine
{
	class Timing
	{
	public:
		Timing();
		~Timing();
		void init(float maxFPS);
		void setMaxFPS(float maxFPS);
		void begin();
		float end();
	private:
		void calculateFPS();
		float _fps;
		float _maxFPS;
		float _frameTime;
		unsigned int _startTicks;
	};
}


