#pragma once
#include "..\..\Engine\src\BaseGame\BaseGame.h"
#include "..\..\Engine\src\Entity\Entity2D\Shape\Square\Square.h"
#include "..\..\Engine\src\Entity\Entity2D\Shape\Triangle\Triangle.h"

class Game : public BaseGame
{
private:
	Triangle *triangle;
	//Square *square;

public:
	Game();
	~Game();
	bool IsRunning();
	void Loop();
	void Draw() override;
};
