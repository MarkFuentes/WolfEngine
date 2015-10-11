#include "ErrorHelper.h"
#include <iostream>
#include <SDL\SDL.h>
namespace WolfEngine
{
	ErrorHelper::ErrorHelper()
	{
	}


	ErrorHelper::~ErrorHelper()
	{
	}

	void ErrorHelper::printError(const std::string & msg)
	{
		std::cout << msg << std::endl;
		std::cout << "Press Any key to quit..." << std::endl;
		int tmp;
		std::cin >> tmp;
		SDL_Quit();
		exit(1);
	}
}

