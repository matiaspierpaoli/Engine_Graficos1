#pragma once
#include "BaseGame/BaseGame.h"
#include "Entity\Entity2D\Shape\Square\Square.h"
#include "Entity\Entity2D\Shape\Triangle\Triangle.h"
#include "Sprite/Sprite.h"

class Game : public BaseGame
{
private:
	Sprite* sprite1;
	Sprite* sprite2;

public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void DeInit() override;
};
