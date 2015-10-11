#pragma once
#include <GL/glew.h>
#include "GLTexture.h"
#include <string>
namespace WolfEngine
{
	class Sprite
	{
	public:
		Sprite();
		~Sprite();
		void Init(float x, float y, float width, float height, std::string texturePath);
		void Draw();
	private:
		float _posX;
		float _posY;
		float _width;
		float _height;
		GLuint _vertexBuffObj;
		GLTexture _texture;
	};
}


