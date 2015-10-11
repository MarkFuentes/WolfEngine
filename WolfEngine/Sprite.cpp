#include "Sprite.h"
#include "Vertex.h"
#include "ResourceManager.h"
#include <cstddef>
namespace WolfEngine
{
	Sprite::Sprite()
	{
		_vertexBuffObj = 0;
	}


	Sprite::~Sprite()
	{
		if (_vertexBuffObj != 0)
		{
			glDeleteBuffers(1, &_vertexBuffObj);
		}
	}

	void Sprite::Init(float x, float y, float width, float height, std::string texturePath)
	{
		_posX = x;
		_posY = y;
		_width = width;
		_height = height;

		_texture = ResourceManager::getTexture(texturePath);

		if (_vertexBuffObj == 0)
		{
			glGenBuffers(1, &_vertexBuffObj);
		}
		Vertex vertexData[6];
		vertexData[0].setPosition((x + width), (y + height));
		vertexData[0].setUV(1.0f, 1.0f);

		vertexData[1].setPosition((x), (y + height));
		vertexData[1].setUV(0.0f, 1.0f);

		vertexData[2].setPosition((x), (y));
		vertexData[2].setUV(0.0f, 0.0f);

		vertexData[3].setPosition((x), (y));
		vertexData[3].setUV(0.0f, 0.0f);

		vertexData[4].setPosition((x + width), (y));
		vertexData[4].setUV(1.0f, 0.0f);

		vertexData[5].setPosition((x + width), (y + height));
		vertexData[5].setUV(1.0f, 1.0f);

		for (int iCounter = 0; iCounter < 6; iCounter++)
		{
			vertexData[iCounter].setColor(255, 0, 255, 255);
		}
		vertexData[1].setColor(0, 0, 255, 255);

		vertexData[4].setColor(0, 255, 0, 255);

		glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffObj);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Sprite::Draw()
	{
		glBindTexture(GL_TEXTURE_2D, _texture.id);
		glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffObj);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
		glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glDisableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}

