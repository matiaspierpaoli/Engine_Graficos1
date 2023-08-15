#pragma once
#include <glfw/include/GLFW/glfw3.h>

class BaseGame
{
private:
	GLFWwindow* window;

public:
	BaseGame();
	~BaseGame();

	void Loop();

};