#include <iostream>
#include "Renderer.h"
#include "glew/include/GL/glew.h"
#include <glfw/include/GLFW/glfw3.h>

Renderer::Renderer(Window* window)
{
	this->window = window;
	float positions[6] = { -0.5f, -0.5f,
						   0.0f, 0.5f, 
						   0.5f, -0.5f};
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)* 2, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);	
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

void Renderer::Draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}