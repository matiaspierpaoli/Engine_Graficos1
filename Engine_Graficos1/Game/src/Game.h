#pragma once
#include "BaseGame/BaseGame.h"
#include "Entity\Entity2D\Shape\Square\Square.h"
#include "Entity\Entity2D\Shape\Triangle\Triangle.h"
#include "Sprite/Sprite.h"

class Game : public BaseGame
{
private:

	Entity2D* pikachu;
	Entity2D* sonic;
	Entity2D* cartel;
	Entity2D* background;
	Entity2D* text;
	Entity2D* logo;

	Entity2D* square1;
	Entity2D* square2;

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

	bool isMovingForward1;
	bool isMovingBackward1;
	bool isMovingLeft1;
	bool isMovingRight1;

	bool isMovingForward2;
	bool isMovingBackward2;
	bool isMovingLeft2;
	bool isMovingRight2;

	std::vector<Frame> pikachuIdleFrames = std::vector<Frame>();
	std::vector<Frame> pikachuRunFrames = std::vector<Frame>();
	std::vector<Frame> sonicIdleFrames = std::vector<Frame>();
	std::vector<Frame> sonicRunFrames = std::vector<Frame>();
	std::vector<Frame> cartelFrames = std::vector<Frame>();

	Animation* pikachuIdleAnim;
	Animation* pikachuRunAnim;
	Animation* sonicIdleAnim;
	Animation* sonicRunAnim;
	Animation* cartelAnim;

	void checkCollisions(Entity2D* player1, Entity2D* player2);

public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void DeInit() override;
};
