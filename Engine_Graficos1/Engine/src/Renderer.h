#pragma once
#include "Window.h"

class Renderer
{
private:
	Window* window;

public:
	Renderer(Window* window);
	~Renderer();
	
	void ClearScreen();
	void SwapWindowBuffers();

};
