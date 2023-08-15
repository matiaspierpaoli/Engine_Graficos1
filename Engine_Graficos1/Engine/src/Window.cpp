#include "Window.h"
#include <glfw/include/GLFW/glfw3.h>

Window::Window(float height, float width)
{
	this->height = height;
	this->width = width;
	CreateWindow();
}

Window::~Window()
{

}


void Window::ProcessWindowEvents()
{
	glfwPollEvents();
}

bool Window::WindowExists()
{
	return window;
}

bool Window::WindowShouldClose()
{
	return glfwWindowShouldClose((GLFWwindow*)window);
}

void Window::CreateWindow()
{
	window = glfwCreateWindow(height, width, "Hello World", NULL, NULL);

	if (!window)
		return;

	glfwMakeContextCurrent((GLFWwindow*)window);

}

void* Window::GetGLFWPointer()
{
	return window;
}
