#pragma once
#include <string>
#include <vector>

#include "Window/Window.h"
#include "Program/Program.h"
#include "Buffers/VertexBuffer.h"
#include "Buffers/IndexBuffer.h"
#include "VertexArray.h"

class Renderer
{
private:
	Window* window;
	Program* program;
	std::vector<glm::mat4> models;
	glm::mat4 view;
	glm::mat4 proj;

	std::vector<VertexBuffer*> vertexBuffers;
	std::vector<IndexBuffer*> indexBuffers;
	std::vector<VertexArray*> vertexArrays;

	unsigned int vao;

public:
	Renderer(Window* window);
	~Renderer();
	
	void ClearScreen();
	void SwapWindowBuffers();
	void Draw(unsigned int vertexBuffer, unsigned int indexBuffer, unsigned int modelId);

	unsigned int GetNewVertexBuffer(const void* data, unsigned int size  );
	unsigned int GetNewIndexBuffer(unsigned int* indices, unsigned int count);

	unsigned int GetNewModelId(glm::mat4 model);
	void SetModel(glm::mat4 model, unsigned int modelId);
};
