#pragma once
#include "Window/Window.h"
#include "Program/Program.h"
#include <string>

class Renderer
{
private:
	Window* window;
	Program program;
public:
	Renderer(Window* window);
	~Renderer();
	
	void ClearScreen();
	void SwapWindowBuffers();
	void Draw();
};
