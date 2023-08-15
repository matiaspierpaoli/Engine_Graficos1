#include <iostream>
#include "Renderer.h"
#include <glfw/include/GLFW/glfw3.h>

Renderer::Renderer(Window* window)
{
	this->window = window;
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