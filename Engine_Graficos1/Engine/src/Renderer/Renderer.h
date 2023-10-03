#pragma once
#include <string>
#include <vector>

#include "Window/Window.h"
#include "Program/Program.h"

class Renderer
{
private:
	Window* window;
	Program* program;
	std::vector<glm::mat4> models;
	glm::mat4 view;
	glm::mat4 proj;

public:
	Renderer(Window* window);
	~Renderer();
	
	void ClearScreen();
	void SwapWindowBuffers();
	void Draw(unsigned int vertexBuffer, unsigned int indexBuffer, unsigned int modelId);

	unsigned int SetNewVertexBuffer(const void* data, unsigned int size  );
	unsigned int SetNewIndexBuffer(const void* indices, unsigned int count);

	unsigned int GetNewModelId(glm::mat4 model);
	void SetModel(glm::mat4 model, unsigned int modelId);
};
