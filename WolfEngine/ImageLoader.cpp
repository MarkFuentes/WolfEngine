#include "ImageLoader.h"
#include <vector>
#include "IoManager.h"
#include "PNGdecoder.h"
namespace WolfEngine
{
	ImageLoader::ImageLoader()
	{
	}


	ImageLoader::~ImageLoader()
	{
	}

	GLTexture ImageLoader::loadPNG(const std::string & filePath)
	{
		GLTexture texture = {};

		std::vector<unsigned char> in;
		std::vector<unsigned char> out;

		unsigned long width;
		unsigned long height;

		if (IoManager::readFileToBuffer(filePath, in) == false)
		{
			ErrorHelper::printError("Failed to load PNG to the buffer.");
		}

		int errorCode = PNGdecoder::decodePNG(out, width, height, &(in[0]), in.size());
		if (errorCode != 0)
		{
			ErrorHelper::printError("decodePNG failed with error: " + std::to_string(errorCode));
		}

		glGenTextures(1, &(texture.id));

		glBindTexture(GL_TEXTURE_2D, texture.id);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);

		texture.width;
		texture.height;

		return texture;
	}
}

