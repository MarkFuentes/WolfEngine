#pragma once
#include <string>
#include <GL/glew.h>
#include "ErrorHelper.h"
namespace WolfEngine
{
	class GLSLProgram
	{
	public:
		GLSLProgram();
		~GLSLProgram();
		void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderfilePath);
		void linkShaders();
		void addAttribute(const std::string& attributeName);
		void compileShader(const std::string& filePath, GLuint id);
		void use();
		void unuse();
		GLuint getUniformLocation(const std::string& uniformName);
	private:
		int _numAttributes;
		GLuint _programID;
		GLuint _vertexShaderID;
		GLuint _fragmentShaderID;
		ErrorHelper* _errHelper;
	};
}


