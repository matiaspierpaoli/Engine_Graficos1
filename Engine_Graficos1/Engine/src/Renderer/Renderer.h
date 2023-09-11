#pragma once
#include "Window/Window.h"
#include "Program/Program.h"
#include <string>

class Renderer
{
private:
	Window* window;
	Program* program;
public:
	Renderer(Window* window);
	~Renderer();
	
	void ClearScreen();
	void SwapWindowBuffers();
	void Draw(unsigned int vertexBuffer, unsigned int indexBuffer);

	unsigned int SetNewVertexBuffer(const void* data, unsigned int size  );
	unsigned int SetNewIndexBuffer(const void* indices, unsigned int count);
};
