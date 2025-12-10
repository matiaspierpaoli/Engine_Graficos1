#include "InputManager.h"

InputManager::InputManager(GLFWwindow* window)
{
	this->window = window;
}

InputManager::~InputManager()
{
}

bool InputManager::IsKeyPressed(unsigned int keyCode)
{
	return (glfwGetKey(window, keyCode) == GLFW_PRESS);
}

bool InputManager::IsKeyJustReleased(unsigned int keyCode)
{
	int currentState = glfwGetKey(window, keyCode);
	int lastState = keyStates[keyCode];

	keyStates[keyCode] = currentState;

	return lastState == GLFW_PRESS && currentState == GLFW_RELEASE;
}
