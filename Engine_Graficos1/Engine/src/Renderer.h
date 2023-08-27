#pragma once
#include "Window.h"
#include <string>

class Renderer
{
private:
	Window* window;

public:
	Renderer(Window* window);
	~Renderer();
	
	void ClearScreen();
	void SwapWindowBuffers();
	void Draw();
	unsigned int CompileShader(const std::string& source, unsigned int type);
	unsigned int CreateShader(const std::string vertexShader, const std::string fragmentShader);
};
