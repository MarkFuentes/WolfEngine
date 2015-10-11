#pragma once
#include <string>
#include <vector>
namespace WolfEngine
{
	class IoManager
	{
	public:
		IoManager();
		~IoManager();
		static bool readFileToBuffer(const std::string& filePath, std::vector<unsigned char>& buffer);
	};
}


