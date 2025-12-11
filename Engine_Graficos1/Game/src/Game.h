#pragma once
#include "BaseGame/BaseGame.h"
#include "Sprite/Sprite.h"
#include "TileMap/TileMap.h"

class Game : public BaseGame
{
private:

	Entity2D* sonic;
	
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
	
	bool isMovingForward1;
	bool isMovingBackward1;
	bool isMovingLeft1;
	bool isMovingRight1;

	float horizontalVelocity = 0.0f;
	float acceleration = 800.0f;
	float friction = 600.0f;
	float maxSpeedRun = 200.0f;
	float maxSpeedSprint = 400.0f;
	
	bool debugCollisionSquares = false;
	
	bool isMovingForward2;
	bool isMovingBackward2;
	bool isMovingLeft2;
	bool isMovingRight2;

	float gravity = 1500.0f;
	float verticalVelocity = 0.0f; 
	bool isGrounded = false; // Boolean to check if player touches the ground
	float jumpForce = 800.0f; // Upwards force
	float coyoteTimeCounter = 0.0f;
	const float COYOTE_TIME_DURATION = 0.15f;
	bool wasGrounded = false;
	
	std::vector<Frame> sonicIdleFrames = std::vector<Frame>();
	std::vector<Frame> sonicRunFrames = std::vector<Frame>();
	std::vector<Frame> sonicSprintFrames = std::vector<Frame>();
	std::vector<Frame> sonicJumpFrames = std::vector<Frame>();

	Animation* sonicIdleAnim;
	Animation* sonicRunAnim;
	Animation* sonicSprintAnim;
	Animation* sonicJumpAnim;

	TileMap* level1TileMap;
	int decorationsLayer;
	int pilarsLayer;
	
	void checkCollisions(Entity2D* player1, Entity2D* player2);
	void checkCollisionsWithWindow(Entity2D* player1);

public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void DeInit() override;
};
