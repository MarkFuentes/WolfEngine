#pragma once
#include "TextureCache.h"
#include <string>
namespace WolfEngine
{
	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();
		static GLTexture getTexture(std::string texturePath);
	private:
		static TextureCache _textureCache;
	};
}


