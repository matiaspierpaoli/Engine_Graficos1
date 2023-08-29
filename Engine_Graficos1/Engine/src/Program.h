#pragma once
#include <string>
#include <fstream>

class Program
{

private:

public:
	Program();
	~Program();

	std::string ReadFile(std::string filePath);
	unsigned int CreateShader(const std::string vertexShader, const std::string fragmentShader);
	unsigned int CompileShader(const std::string& source, unsigned int type);
	
};