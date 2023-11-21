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

#pragma endregion 

	int sonicSpriteSheetWidth = 830;
	int sonicSpriteSheetHeight = 465;

	#pragma region Cartel

	cartelFrames.push_back(Frame(140,     190.57, sonicSpriteSheetHeight - 356, sonicSpriteSheetHeight - 302));
	cartelFrames.push_back(Frame(190.57,  239.45, sonicSpriteSheetHeight - 356, sonicSpriteSheetHeight - 302));
	cartelFrames.push_back(Frame(239.45,  288.70, sonicSpriteSheetHeight - 356, sonicSpriteSheetHeight - 302));
	cartelFrames.push_back(Frame(288.70,  338,    sonicSpriteSheetHeight - 356, sonicSpriteSheetHeight - 302));
	cartelFrames.push_back(Frame(338,     387,    sonicSpriteSheetHeight - 356, sonicSpriteSheetHeight - 302));

#pragma endregion 

	cartel = new Sprite("res/Sonic_Mania_Sprite_Sheet.png", 5, cartelFrames.at(0));
	cartel->Scale(100, 100);
	cartel->Translate(250, 400);

	Animation* cartelAnim = new Animation(2, sonicSpriteSheetWidth, sonicSpriteSheetHeight, cartelFrames);

	static_cast<Sprite*>(cartel)->AddAnimation(cartelAnim);

	#pragma region Idle 
	sonicIdleFrames.push_back(Frame(55,  83,  sonicSpriteSheetHeight - 50, sonicSpriteSheetHeight - 5));
	sonicIdleFrames.push_back(Frame(83,  115, sonicSpriteSheetHeight - 50, sonicSpriteSheetHeight - 5));
	sonicIdleFrames.push_back(Frame(115, 146, sonicSpriteSheetHeight - 50, sonicSpriteSheetHeight - 5));
	sonicIdleFrames.push_back(Frame(146, 177, sonicSpriteSheetHeight - 50, sonicSpriteSheetHeight - 5));
	sonicIdleFrames.push_back(Frame(177, 209, sonicSpriteSheetHeight - 50, sonicSpriteSheetHeight - 5));
	sonicIdleFrames.push_back(Frame(209, 239, sonicSpriteSheetHeight - 50, sonicSpriteSheetHeight - 5));
	sonicIdleFrames.push_back(Frame(239, 270, sonicSpriteSheetHeight - 50, sonicSpriteSheetHeight - 5));
	sonicIdleFrames.push_back(Frame(30,  63,  sonicSpriteSheetHeight - 97, sonicSpriteSheetHeight - 54));
	sonicIdleFrames.push_back(Frame(63,  91,  sonicSpriteSheetHeight - 97, sonicSpriteSheetHeight - 54));
	sonicIdleFrames.push_back(Frame(91,  126, sonicSpriteSheetHeight - 97, sonicSpriteSheetHeight - 54));
	sonicIdleFrames.push_back(Frame(126, 160, sonicSpriteSheetHeight - 97, sonicSpriteSheetHeight - 54));
	sonicIdleFrames.push_back(Frame(160, 189, sonicSpriteSheetHeight - 97, sonicSpriteSheetHeight - 54));
	

#pragma endregion 

	#pragma region Run 
	sonicRunFrames.push_back(Frame(284, 316, sonicSpriteSheetHeight - 145, sonicSpriteSheetHeight - 100));
	sonicRunFrames.push_back(Frame(316, 346, sonicSpriteSheetHeight - 145, sonicSpriteSheetHeight - 100));
	sonicRunFrames.push_back(Frame(346, 386, sonicSpriteSheetHeight - 145, sonicSpriteSheetHeight - 100));
	sonicRunFrames.push_back(Frame(386, 426, sonicSpriteSheetHeight - 145, sonicSpriteSheetHeight - 100));
	sonicRunFrames.push_back(Frame(426, 465, sonicSpriteSheetHeight - 145, sonicSpriteSheetHeight - 100));
	sonicRunFrames.push_back(Frame(465, 498, sonicSpriteSheetHeight - 145, sonicSpriteSheetHeight - 100));
	sonicRunFrames.push_back(Frame(498, 530, sonicSpriteSheetHeight - 145, sonicSpriteSheetHeight - 100));
	sonicRunFrames.push_back(Frame(530, 563, sonicSpriteSheetHeight - 145, sonicSpriteSheetHeight - 100));
	sonicRunFrames.push_back(Frame(563, 602, sonicSpriteSheetHeight - 145, sonicSpriteSheetHeight - 100));
	sonicRunFrames.push_back(Frame(602, 642, sonicSpriteSheetHeight - 145, sonicSpriteSheetHeight - 100));
	sonicRunFrames.push_back(Frame(642, 681, sonicSpriteSheetHeight - 145, sonicSpriteSheetHeight - 100));
	sonicRunFrames.push_back(Frame(681, 716, sonicSpriteSheetHeight - 145, sonicSpriteSheetHeight - 100));
#pragma endregion 


	sonic = new Sprite("res/Sonic_Mania_Sprite_Sheet.png",  12, sonicIdleFrames.at(0));
	sonic->Scale(100, 100);
	sonic->Translate(250, 100);

	Animation* sonicIdleAnim = new Animation(3, sonicSpriteSheetWidth, sonicSpriteSheetHeight, sonicIdleFrames);
	Animation* sonicRunAnim = new Animation(0.8, sonicSpriteSheetWidth, sonicSpriteSheetHeight, sonicRunFrames);
	
	static_cast<Sprite*>(sonic)->AddAnimation(sonicIdleAnim);
	static_cast<Sprite*>(sonic)->AddAnimation(sonicRunAnim);

	background = new Sprite("res/background.png", 1, Frame(0, 512, 0, 257));
	background->Translate(250, 257);
	background->Scale(800, 530);

	isMovingForward = false;
	isMovingBackward = false;
	isMovingLeft = false;
	isMovingRight = false;
}

void Game::DeInit()
{
	if (cartel != nullptr)
	{
		delete cartel;
		cartel = nullptr;
	}

	if (sonic != nullptr)
	{
		delete sonic;
		sonic = nullptr;
	}

	if (background != nullptr)
	{
		delete background;
		background = nullptr;
	}
}

void Game::Update()
{	
	static_cast<Sprite*>(cartel)->UpdateFrame(0);

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
		isMovingForward = false;
		isMovingBackward = false;
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
		isMovingLeft = false;
		isMovingRight = false;
	}
	
	if (IsKeyPressed(KEY_Q))
		sonic->Rotate(defaultRotation * time->GetDeltaTime());

	if (IsKeyPressed(KEY_E))
		sonic->Rotate(-defaultRotation * time->GetDeltaTime());

	if (IsKeyPressed(KEY_X))
		scaleVectorPlayer1 = 1;
	else if (IsKeyPressed(KEY_Z))
		scaleVectorPlayer1 = -1;
	else
		scaleVectorPlayer1 = 0;

	#pragma endregion

	if (!moveVectorPlayer1.x == 0 || !moveVectorPlayer1.y == 0)
	{		
		static_cast<Sprite*>(sonic)->UpdateFrame(1);

		traslateX = moveVectorPlayer1.x * defaultTranslation.x * time->GetDeltaTime();
		traslateY = moveVectorPlayer1.y * defaultTranslation.y * time->GetDeltaTime();

		sonic->Translate(traslateX, traslateY);
		checkCollisions(sonic, cartel);
	}

	if (!scaleVectorPlayer1 == 0)
	{
		scaleX = scaleVectorPlayer1 * defaultScale.x * time->GetDeltaTime();
		scaleY = scaleVectorPlayer1 * defaultScale.y * time->GetDeltaTime();

		sonic->Scale(scaleX, scaleY);
		checkCollisions(sonic, cartel);
	}
	
	if (!isMovingForward && !isMovingBackward && !isMovingLeft && !isMovingRight)
	{
		static_cast<Sprite*>(sonic)->UpdateFrame(0);
	}

	static_cast<Sprite*>(background)->Draw();
	static_cast<Sprite*>(cartel)->Draw();
	static_cast<Sprite*>(sonic)->Draw();
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