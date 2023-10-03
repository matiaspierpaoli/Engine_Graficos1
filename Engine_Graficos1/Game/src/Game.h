#pragma once
#include "BaseGame/BaseGame.h"
#include "Entity\Entity2D\Shape\Square\Square.h"
#include "Entity\Entity2D\Shape\Triangle\Triangle.h"

class Game : public BaseGame
{
private:
	Triangle *triangle;
	//Square *square;

public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void DeInit() override;
};
