#pragma once
#include <string>
namespace WolfEngine
{
	class ErrorHelper
	{
	public:
		ErrorHelper();
		~ErrorHelper();
		static void printError(const std::string& msg);
	};

}

