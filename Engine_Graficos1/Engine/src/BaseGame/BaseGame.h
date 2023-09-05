#pragma once
#include <glfw/include/GLFW/glfw3.h>

#include "Entity/Entity2D/Shape/Square/Square.h"

class BaseGame
{
private:
	void* window;
	void* renderer;
	bool isRunning;

	Entity* entity;

public:
	BaseGame();
	~BaseGame();

	void Loop();
	bool IsRunning();
};