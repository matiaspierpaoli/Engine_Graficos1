#pragma once

#include "BaseGame/BaseGame.h"
#include "Entity/Entity2D/Shape/Triangle/Triangle.h"
#include "Entity/Entity2D/Shape/Square/Square.h"

class Game : public BaseGame
{
private:
	Entity *triangle;
	Entity *square;

public:
	Game();
	~Game();
	bool IsRunning();
	void Loop();
};
