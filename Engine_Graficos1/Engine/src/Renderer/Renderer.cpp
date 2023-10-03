#include <iostream>

#include "Renderer.h"
#include "Buffers/IndexBuffer.h"
#include "glew/include/GL/glew.h"
#include <glfw/include/GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

Renderer::Renderer(Window* window)
{
	this->window = window;
	
	program = new Program();

	proj = glm::ortho(0.0f, window->GetHeight(), 0.0f, window->GetWidth(), -1.0f, 1.0f);
	view = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	unsigned int shader = program->CreateShader(program->ReadFile("shaders/vertexShader.shader"), program->ReadFile("shaders/fragmentShader.shader"));
	glUseProgram(shader); 

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}

Renderer::~Renderer()
{
	delete window;
	delete program;

	for (int i = 0; i < vertexArrays.size(); i++)	
		delete vertexArrays[i];
	for (int i = 0; i < indexBuffers.size(); i++)
		delete indexBuffers[i];
	
}

void Renderer::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::SwapWindowBuffers()
{
	if (!window || !window->WindowExists())
		std::cout << "RENDERER ERROR: Window does not exist" << std::endl;

	glfwSwapBuffers((GLFWwindow*) window->GetGLFWPointer());
}

void Renderer::Draw(unsigned int vertexBuffer, unsigned int indexBuffer, unsigned int modelId)
{
	VertexBuffer* vb = vertexBuffers[vertexBuffer];
	IndexBuffer* ib = indexBuffers[indexBuffer];
	VertexArray* va = vertexArrays[vertexBuffer];

	vb->Bind();
	va->Bind();
	ib->Bind();

	program->SetUniformMat4F("mvp", proj * view * models[modelId]);
	//program->SetUniform4f("uColor", 1.0f, 0.0f, 0.0f, 1.0f);
	//glDrawArrays(GL_TRIANGLES, 0, 3);


	glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, nullptr);
}

unsigned int Renderer::GetNewVertexBuffer(const void* data, unsigned int size)
{
	unsigned int bufferID = vertexArrays.size();

	VertexBuffer* vb = new VertexBuffer(data, size, true);
	vertexBuffers.push_back(vb);

	VertexBufferLayout layout;
	layout.Push<float>(2); //Position
	layout.Push<float>(4); //Color

	VertexArray* va = new VertexArray();
	va->AddBuffer(vb, layout);

	vertexArrays.push_back(va);

	return bufferID;
}

unsigned int Renderer::GetNewIndexBuffer(unsigned int* indices, unsigned int indexAmmount)
{
	unsigned int bufferID = indexBuffers.size();

	IndexBuffer* ib = new IndexBuffer(indices, indexAmmount);
	indexBuffers.push_back(ib);

	return bufferID;
}

unsigned int Renderer::GetNewModelId(glm::mat4 model)
{
	unsigned int newModelId = models.size();
	models.push_back(model);

	return newModelId;
}

void Renderer::SetModel(glm::mat4 model, unsigned int modelId)
{
	models[modelId] = model;
}