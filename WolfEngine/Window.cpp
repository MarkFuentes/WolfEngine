#include "Window.h"
#include "ErrorHelper.h"

namespace WolfEngine
{
	Window::Window()
	{
	}


	Window::~Window()
	{
	}

	int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags)
	{
		Uint32 flags = SDL_WINDOW_OPENGL;
		if (currentFlags & INVISIBLE)
		{
			flags |= SDL_WINDOW_HIDDEN;
		}
		if (currentFlags & FULLSCREEN)
		{
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		}
		if (currentFlags & BORDERLESS)
		{
			flags |= SDL_WINDOW_BORDERLESS;
		}

		_window = SDL_CreateWindow(windowName.c_str(),
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);

		SDL_GLContext glContext = SDL_GL_CreateContext(_window);
		GLenum glError = glewInit();

		if (_window == nullptr)
		{
			//fatalError("SDL Window could not be created.");
			ErrorHelper::printError("SDL window could not be created.");
		}

		if (glContext == nullptr)
		{
			//fatalError("SDL_GL could not be created.");
			ErrorHelper::printError("SDL_GL could not be created.");
		}

		if (glError != GLEW_OK)
		{
			//fatalError("Could not initialize glew");
			ErrorHelper::printError("Could not initialize glew.");
		}

		glClearColor(0.0f, 0.0f, 0.6f, 1.0f);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		return 0;
	}

	void Window::Swap()
	{
		SDL_GL_SwapWindow(_window);
	}
}

