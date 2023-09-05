#include <iostream>

#include "Renderer.h"
#include "glew/include/GL/glew.h"
#include <glfw/include/GLFW/glfw3.h>

Renderer::Renderer(Window* window)
{
	this->window = window;
	
	program = Program();

	/*float positions[] = { -0.5f, -0.5f,
						   0.5f, -0.5f, 
						   0.5f, 0.5f,
						   -0.5f, 0.5f};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0,

	};*/

	/*unsigned int vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), data, GL_STATIC_DRAW);*/

	/*glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)* 2, 0);*/

	//glBindBuffer(GL_ARRAY_BUFFER, 0);	

	/*unsigned int indexBuffer;
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);*/

	unsigned int shader = program.CreateShader(program.ReadFile("res/vertexShader.shader"), program.ReadFile("res/fragmentShader.shader"));
	glUseProgram(shader);
}

Renderer::~Renderer()
{
	delete window;
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

void Renderer::Draw(unsigned int vertexBuffer, unsigned int indexBuffer)
{
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

unsigned int Renderer::SetNewVertexBuffer(const void* data, unsigned int size)
{
	unsigned int vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); 

	return vertexBuffer;
}

unsigned int Renderer::SetNewIndexBuffer(const void* data, unsigned int count)
{
	unsigned int indexBuffer;
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);

	return indexBuffer;
}
