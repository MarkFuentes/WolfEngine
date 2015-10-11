#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include <string>
namespace WolfEngine
{
	enum windowFlags { INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4 };

	class Window
	{
	public:
		Window();
		~Window();
		int create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);
		void Swap();
		int screemWidth()
		{
			_screenWidth;
		}
		int screenHeight()
		{
			_screenHeight;
		}
	private:
		SDL_Window* _window;
		int _screenWidth;
		int _screenHeight;
	};
}

