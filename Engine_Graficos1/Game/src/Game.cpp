#include "Game.h"
#include <iostream>

#pragma region keyCodes

#define KEY_W 87
#define KEY_A 65
#define KEY_S 83
#define KEY_D 68
#define KEY_Q 81
#define KEY_E 69
#define KEY_Z 90
#define KEY_X 88

#define KEY_I 73
#define KEY_J 74
#define KEY_K 75
#define KEY_L 76
#define KEY_U 85
#define KEY_O 79
#define KEY_N 78
#define KEY_M 77

#pragma endregion

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init()
{
	OnStart(480, 480, "Game");

	traslateX = 0.f;
	traslateY = 0.f;
	
	defaultTranslation.x = 50.0f;
	defaultTranslation.y = 50.0f; 

	defaultRotation = 10.0f;

	defaultScale.x = 10.0f;
	defaultScale.y = 10.0f;


	#pragma region Link - Forward

	linkForwardFrames.push_back(Frame(0,   24,  221, 256));
	linkForwardFrames.push_back(Frame(24,  48,  221, 256));
	linkForwardFrames.push_back(Frame(48,  72,  221, 256));
	linkForwardFrames.push_back(Frame(72,  96,  221, 256));
	linkForwardFrames.push_back(Frame(96,  120, 221, 256));
	linkForwardFrames.push_back(Frame(120, 144, 221, 256));
	linkForwardFrames.push_back(Frame(144, 168, 221, 256));
	linkForwardFrames.push_back(Frame(168, 192, 221, 256));
	linkForwardFrames.push_back(Frame(192, 216, 221, 256));
	linkForwardFrames.push_back(Frame(216, 240, 221, 256));
	linkForwardFrames.push_back(Frame(240, 264, 221, 256));
	linkForwardFrames.push_back(Frame(264, 288, 221, 256));

#pragma endregion 

	#pragma region Link - Backward

	linkBackwardFrames.push_back(Frame(0,   24,  158, 186));
	linkBackwardFrames.push_back(Frame(24,  48,  158, 186));
	linkBackwardFrames.push_back(Frame(48,  72,  158, 186));
	linkBackwardFrames.push_back(Frame(72,  96,  158, 186));
	linkBackwardFrames.push_back(Frame(96,  120, 158, 186));
	linkBackwardFrames.push_back(Frame(120, 144, 158, 186));
	linkBackwardFrames.push_back(Frame(144, 168, 158, 186));
	linkBackwardFrames.push_back(Frame(168, 192, 158, 186));
	linkBackwardFrames.push_back(Frame(192, 216, 158, 186));
	linkBackwardFrames.push_back(Frame(216, 240, 158, 186));
	linkBackwardFrames.push_back(Frame(240, 264, 158, 186));
	linkBackwardFrames.push_back(Frame(264, 288, 158, 186));

#pragma endregion 

	#pragma region Link - Left

	linkLeftFrames.push_back(Frame(0,   24,  126, 155));
	linkLeftFrames.push_back(Frame(24,  48,  126, 155));
	linkLeftFrames.push_back(Frame(48,  72,  126, 155));
	linkLeftFrames.push_back(Frame(72,  96,  126, 155));
	linkLeftFrames.push_back(Frame(96,  120, 126, 155));
	linkLeftFrames.push_back(Frame(120, 144, 126, 155));
	linkLeftFrames.push_back(Frame(144, 168, 126, 155));
	linkLeftFrames.push_back(Frame(168, 192, 126, 155));
	linkLeftFrames.push_back(Frame(192, 216, 126, 155));
	linkLeftFrames.push_back(Frame(216, 240, 126, 155));
	linkLeftFrames.push_back(Frame(240, 264, 126, 155));
	linkLeftFrames.push_back(Frame(264, 288, 126, 155));

#pragma endregion 

	#pragma region Link - Right

	linkRightFrames.push_back(Frame(0,   24,  189, 219));
	linkRightFrames.push_back(Frame(24,  48,  189, 219));
	linkRightFrames.push_back(Frame(48,  72,  189, 219));
	linkRightFrames.push_back(Frame(72,  96,  189, 219));
	linkRightFrames.push_back(Frame(96,  120, 189, 219));
	linkRightFrames.push_back(Frame(120, 144, 189, 219));
	linkRightFrames.push_back(Frame(144, 168, 189, 219));
	linkRightFrames.push_back(Frame(168, 192, 189, 219));
	linkRightFrames.push_back(Frame(192, 216, 189, 219));
	linkRightFrames.push_back(Frame(216, 240, 189, 219));
	linkRightFrames.push_back(Frame(240, 264, 189, 219));
	linkRightFrames.push_back(Frame(264, 288, 189, 219));

#pragma endregion 

	link = new Sprite("res/linkSpriteSheet.jpg", 12, linkForwardFrames.at(0));
	link->Scale(100, 100);
	link->Translate(250, 200);

	Animation* linkForwardAnim = new Animation(1, 288, 256, linkForwardFrames);
	Animation* linkBackwardAnim = new Animation(1, 288, 256, linkBackwardFrames);
	Animation* linkLeftAnim = new Animation(1, 288, 256, linkLeftFrames);
	Animation* linkRightAnim = new Animation(1, 288, 256, linkRightFrames);

	static_cast<Sprite*>(link)->AddAnimation(linkForwardAnim);
	static_cast<Sprite*>(link)->AddAnimation(linkBackwardAnim);
	static_cast<Sprite*>(link)->AddAnimation(linkLeftAnim);
	static_cast<Sprite*>(link)->AddAnimation(linkRightAnim);

	#pragma region Idle - Horizontal
	sonicIdleFrames.push_back(Frame(275, 410, 830, 1000));
	sonicIdleFrames.push_back(Frame(410, 545, 830, 1000));
	sonicIdleFrames.push_back(Frame(545, 670, 830, 1000));
	sonicIdleFrames.push_back(Frame(670, 780, 830, 1000));
	sonicIdleFrames.push_back(Frame(780, 890, 830, 1000));
	sonicIdleFrames.push_back(Frame(895, 1005, 830, 1000));

#pragma endregion 

	#pragma region Run - Horizontal and Vertical
	sonicRunFrames.push_back(Frame(620, 760, 1020 - 470, 1020 - 275));
	sonicRunFrames.push_back(Frame(760, 875, 1020 - 470, 1020 - 275));
	sonicRunFrames.push_back(Frame(875, 994, 1020 - 470, 1020 - 275));
	sonicRunFrames.push_back(Frame(994, 1150, 1020 - 470, 1020 - 275));
	sonicRunFrames.push_back(Frame(620, 760, 1020 - 660, 1020 - 470));
	sonicRunFrames.push_back(Frame(760, 890, 1020 - 660, 1020 - 470));
	sonicRunFrames.push_back(Frame(890, 1028, 1020 - 660, 1020 - 470));
	sonicRunFrames.push_back(Frame(1028, 1200, 1020 - 660, 1020 - 470));
	sonicRunFrames.push_back(Frame(610, 753, 1020 - 835, 1020 - 660));
	sonicRunFrames.push_back(Frame(753, 900, 1020 - 835, 1020 - 660));
	sonicRunFrames.push_back(Frame(900, 1050, 1020 - 835, 1020 - 660));
	sonicRunFrames.push_back(Frame(1050, 1188, 1020 - 835, 1020 - 660));
#pragma endregion 


	sonicIdleEntity = new Sprite("res/sonicSpriteSheet.png",  6, sonicIdleFrames.at(0));
	sonicIdleEntity->Scale(100, 100);
	sonicIdleEntity->Translate(350, 400);

	sonicRunEntity = new Sprite("res/sonicSpriteSheet.png", 12, sonicRunFrames.at(0));
	sonicRunEntity->Scale(100, 100);
	sonicRunEntity->Translate(100, 400);

	Animation* sonicIdleAnim = new Animation(3, 1200, 1020, sonicIdleFrames);
	Animation* sonicRunAnim = new Animation(0.8, 1200, 1020, sonicRunFrames);
	
	static_cast<Sprite*>(sonicIdleEntity)->AddAnimation(sonicIdleAnim);
	static_cast<Sprite*>(sonicRunEntity)->AddAnimation(sonicRunAnim);

	isMovingForward = false;
	isMovingBackward = false;
	isMovingLeft = false;
	isMovingRight = false;
}

void Game::DeInit()
{
	if (link != nullptr)
	{
		delete link;
		link = nullptr;
	}

	if (sonicIdleEntity != nullptr)
	{
		delete sonicIdleEntity;
		sonicIdleEntity = nullptr;
	}

	if (sonicRunEntity != nullptr)
	{
		delete sonicRunEntity;
		sonicRunEntity = nullptr;
	}
}

void Game::Update()
{	
	static_cast<Sprite*>(sonicIdleEntity)->UpdateFrame(0);
	static_cast<Sprite*>(sonicRunEntity)->UpdateFrame(0);

	#pragma region Input

	// Player 1 
	if (IsKeyPressed(KEY_W))
	{
		moveVectorPlayer1.y = 1;
		isMovingForward = true;
		isMovingBackward = false;
		isMovingLeft = false;
		isMovingRight = false;
	}
	else if (IsKeyPressed(KEY_S))
	{
		moveVectorPlayer1.y = -1;
		isMovingForward = false;
		isMovingBackward = true;
		isMovingLeft = false;
		isMovingRight = false;
	}
	else
	{
		moveVectorPlayer1.y = 0;
	}

	if (IsKeyPressed(KEY_A))
	{
		moveVectorPlayer1.x = -1;	
		isMovingForward = false;
		isMovingBackward = false;
		isMovingLeft = true;
		isMovingRight = false;
	}
	else if (IsKeyPressed(KEY_D))
	{
		moveVectorPlayer1.x = 1;	
		isMovingForward = false;
		isMovingBackward = false;
		isMovingLeft = false;
		isMovingRight = true;
	}
	else
	{
		moveVectorPlayer1.x = 0;
	}
	
	if (IsKeyPressed(KEY_Q))
		link->Rotate(defaultRotation * time->GetDeltaTime());

	if (IsKeyPressed(KEY_E))
		link->Rotate(-defaultRotation * time->GetDeltaTime());

	if (IsKeyPressed(KEY_X))
		scaleVectorPlayer1 = 1;
	else if (IsKeyPressed(KEY_Z))
		scaleVectorPlayer1 = -1;
	else
		scaleVectorPlayer1 = 0;

	#pragma endregion

	if (!moveVectorPlayer1.x == 0 || !moveVectorPlayer1.y == 0)
	{
		if (isMovingForward)
			static_cast<Sprite*>(link)->UpdateFrame(0);
		if (isMovingBackward)
			static_cast<Sprite*>(link)->UpdateFrame(1);
		if (isMovingLeft)
			static_cast<Sprite*>(link)->UpdateFrame(2);
		if (isMovingRight)
			static_cast<Sprite*>(link)->UpdateFrame(3);


		traslateX = moveVectorPlayer1.x * defaultTranslation.x * time->GetDeltaTime();
		traslateY = moveVectorPlayer1.y * defaultTranslation.y * time->GetDeltaTime();

		link->Translate(traslateX, traslateY);
		checkCollisions(link, sonicIdleEntity);
		checkCollisions(link, sonicRunEntity);
	}

	if (!scaleVectorPlayer1 == 0)
	{
		scaleX = scaleVectorPlayer1 * defaultScale.x * time->GetDeltaTime();
		scaleY = scaleVectorPlayer1 * defaultScale.y * time->GetDeltaTime();

		link->Scale(scaleX, scaleY);
		checkCollisions(link, sonicIdleEntity);
		checkCollisions(link, sonicRunEntity);
	}
	
	static_cast<Sprite*>(sonicIdleEntity)->Draw();
	static_cast<Sprite*>(sonicRunEntity)->Draw();
	static_cast<Sprite*>(link)->Draw();
}

void Game::checkCollisions(Entity2D* player1, Entity2D* player2)
{
	while (collisionManager->checkEntityToEntityCollision(player1, player2))
	{
		if (!moveVectorPlayer1.x == 0 || !moveVectorPlayer1.y == 0 ||
			!moveVectorPlayer2.x == 0 || !moveVectorPlayer2.y == 0)
			player1->Translate(-traslateX, -traslateY);

		if (!scaleVectorPlayer1 == 0 || !scaleVectorPlayer2 == 0)
			player1->Scale(-scaleX, -scaleY);
	}

	while (collisionManager->checkEntityToWindowCollision(player1, (Window*)window))
	{
		if (!moveVectorPlayer1.x == 0 || !moveVectorPlayer1.y == 0 ||
			!moveVectorPlayer2.x == 0 || !moveVectorPlayer2.y == 0)
			player1->Translate(-traslateX, -traslateY);
		
		if (!scaleVectorPlayer1 == 0 || !scaleVectorPlayer2 == 0)
			player1->Scale(-scaleX, -scaleY);
	}
}