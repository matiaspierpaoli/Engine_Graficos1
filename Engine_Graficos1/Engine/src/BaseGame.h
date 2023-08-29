#pragma once
#include <glfw/include/GLFW/glfw3.h>

class BaseGame
{
private:
	void* window;
	void* renderer;
	bool isRunning;

public:
	BaseGame();
	~BaseGame();

	void Loop();
	bool IsRunning();
};