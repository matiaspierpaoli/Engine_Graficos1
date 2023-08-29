#include <iostream>

#include "glew/include/GL/glew.h"
#include "Program.h"

Program::Program()
{
}

Program::~Program()
{
}

std::string Program::ReadFile(std::string filePath)
{
	try
	{
		std::ifstream inputStream;
		std::string line;
		const int bufferSize = 240;

		inputStream.open(filePath);

		while (!inputStream.eof())
		{
			char temp[bufferSize];
			inputStream.getline(temp, bufferSize);

			line += temp;
			line += "\n";
		}

		inputStream.close();

		return line;
	}
	catch (...)
	{
		std::cout << "Could not open file located in: " + filePath << std::endl;
		return 0;
	}
}

unsigned int Program::CreateShader(const std::string vertexShader, const std::string fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(vertexShader, GL_VERTEX_SHADER);
	unsigned int fs = CompileShader(fragmentShader, GL_FRAGMENT_SHADER);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteProgram(vs);
	glDeleteProgram(fs);

	return program;
}

unsigned int Program::CompileShader(const std::string& source, unsigned int type)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int lenght;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
		char* message = (char*)alloca(lenght * sizeof(char));
		glGetShaderInfoLog(id, lenght, &lenght, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}