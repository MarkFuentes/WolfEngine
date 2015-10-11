#pragma once
#include <GL\glew.h>
namespace WolfEngine
{
	struct Position
	{
		float _posX;
		float _posY;
	};
	struct Color
	{
		GLubyte _red;
		GLubyte _green;
		GLubyte _blue;
		GLubyte _alpha;
	};
	struct UV
	{
		float u;
		float v;
	};
	struct Vertex
	{
		Position position;
		Color color;
		UV uv;
		void setPosition(float x, float y)
		{
			position._posX = x;
			position._posY = y;
		}
		void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
		{
			color._red = r;
			color._green = g;
			color._blue = b;
			color._alpha = a;
		}
		void setUV(float u, float v)
		{
			uv.u = u;
			uv.v = v;
		}
	};
}
