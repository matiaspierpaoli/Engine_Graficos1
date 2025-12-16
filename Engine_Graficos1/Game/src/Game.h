#pragma once
#include "BaseGame/BaseGame.h"
#include "Sprite/Sprite.h"
#include "TileMap/TileMap.h"

enum TankDirections
{
	Up = 0,
	Left,
	Down,
	Right
};


class Game : public BaseGame
{
private:

	Entity2D* tank;
	TankDirections tankDirection;
	
	int windowWidth;
	int windowHeight;

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
	
	bool debugCollisionSquares = false;

	std::vector<Frame> tankMoveUpFrames = std::vector<Frame>();
	std::vector<Frame> tankMoveLeftFrames = std::vector<Frame>();
	std::vector<Frame> tankMoveDownFrames = std::vector<Frame>();
	std::vector<Frame> tankMoveRightFrames = std::vector<Frame>();

	Animation* tankMoveUpAnim;
	Animation* tankMoveDownAnim;
	Animation* tankMoveLeftAnim;
	Animation* tankMoveRightAnim;

	TileMap* level1TileMap;
	int treesLayer;
	int bricksLayer;
	
	void checkCollisions(Entity2D* player1, Entity2D* player2);
	void checkCollisionsWithWindow(Entity2D* player1);

public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void DeInit() override;
};
