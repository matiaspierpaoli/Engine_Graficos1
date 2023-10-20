#pragma once
#include "BaseGame/BaseGame.h"
#include "Entity\Entity2D\Shape\Square\Square.h"
#include "Entity\Entity2D\Shape\Triangle\Triangle.h"
#include "Sprite/Sprite.h"

class Game : public BaseGame
{
private:
	Entity2D* player1;
	Entity2D* player2;
	float traslateX;
	float traslateY;
	float defaultTranslation;
	void checkCollisions(Entity2D* player);

public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void DeInit() override;
};
