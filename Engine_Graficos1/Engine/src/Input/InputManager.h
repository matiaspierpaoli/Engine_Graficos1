#pragma once
#include "Exports.h"
#include "glfw/include/GLFW/glfw3.h"
#include <unordered_map>


class GraficosEngine_API InputManager
{
private:
	GLFWwindow* window;
	std::unordered_map<unsigned int, int> keyStates;

public:
	InputManager(GLFWwindow* window);
	~InputManager();

	bool IsKeyPressed(unsigned int keyCode);
	bool IsKeyJustReleased(unsigned int keyCode);
};