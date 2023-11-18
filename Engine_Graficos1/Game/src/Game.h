#pragma once
#include "BaseGame/BaseGame.h"
#include "Entity\Entity2D\Shape\Square\Square.h"
#include "Entity\Entity2D\Shape\Triangle\Triangle.h"
#include "Sprite/Sprite.h"

class Game : public BaseGame
{
private:
	Entity2D* link;

	Entity2D* sonicIdleEntity;
	Entity2D* sonicRunEntity;

	float traslateX;
	float traslateY;
	float scaleX;
	float scaleY;
	Vector2 defaultTranslation;
	float defaultRotation;
	Vector2 defaultScale;
	Vector2 moveVectorPlayer1;
	Vector2 moveVectorPlayer2;
	float scaleVectorPlayer1;
	float scaleVectorPlayer2;

	bool isMovingForward;
	bool isMovingBackward;
	bool isMovingLeft;
	bool isMovingRight;
	
	std::vector<Frame> linkForwardFrames = std::vector<Frame>();
	std::vector<Frame> linkBackwardFrames = std::vector<Frame>();
	std::vector<Frame> linkLeftFrames = std::vector<Frame>();
	std::vector<Frame> linkRightFrames = std::vector<Frame>();
	std::vector<Frame> sonicIdleFrames = std::vector<Frame>();
	std::vector<Frame> sonicRunFrames = std::vector<Frame>();

	void checkCollisions(Entity2D* player1, Entity2D* player2);

public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void DeInit() override;
};
