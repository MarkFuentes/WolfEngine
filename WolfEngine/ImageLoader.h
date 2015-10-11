#pragma once
#include "GLTexture.h"
#include <string>
#include "ErrorHelper.h"
namespace WolfEngine
{
	class ImageLoader
	{
	public:
		ImageLoader();
		~ImageLoader();
		static GLTexture loadPNG(const std::string& filePath);
	};
}


