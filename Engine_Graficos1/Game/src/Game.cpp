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
	
	defaultTranslation.x = 10.0f;
	defaultTranslation.y = 10.0f; 

	defaultRotation = 10.0f;

	defaultScale.x = 10.0f;
	defaultScale.y = 10.0f;

	player1 = new Sprite("res/linkAnimationBackward.png", 9, 0);
	player1->Scale(100, 100);
	player1->Translate(150, 200);

	player2 = new Sprite("res/linkAnimationForward.png", 9, 0);
	player2->Scale(100, 100);
	player2->Translate(300, 300);

	Animation* linkWalkAnim = new Animation(1, 9);
	Animation* linkBackAnim = new Animation(1, 9);
	static_cast<Sprite*>(player1)->SetAnim(linkBackAnim);
	static_cast<Sprite*>(player2)->SetAnim(linkWalkAnim);
}

void Game::DeInit()
{
	delete player1;
	delete player2;
}

void Game::Update()
{	
	#pragma region Input

	// Player 1 
	if (IsKeyPressed(KEY_W))	
		moveVectorPlayer1.y = 1;
	else if (IsKeyPressed(KEY_S))
		moveVectorPlayer1.y = -1;	
	else 
		moveVectorPlayer1.y = 0;

	if (IsKeyPressed(KEY_A))	
		moveVectorPlayer1.x = -1;	
	else if (IsKeyPressed(KEY_D))	
		moveVectorPlayer1.x = 1;	
	else	
		moveVectorPlayer1.x = 0;
	
	if (IsKeyPressed(KEY_Q))
		player1->Rotate(defaultRotation * time->GetDeltaTime());

	if (IsKeyPressed(KEY_E))
		player1->Rotate(-defaultRotation * time->GetDeltaTime());

	if (IsKeyPressed(KEY_X))
		player1->Scale(defaultScale.x * time->GetDeltaTime(), defaultScale.y * time->GetDeltaTime());

	if (IsKeyPressed(KEY_Z))
		player1->Scale(-defaultScale.x * time->GetDeltaTime(), -defaultScale.y * time->GetDeltaTime());

	// Player 2 
	if (IsKeyPressed(KEY_I))	
		moveVectorPlayer2.y = 1;	
	else if (IsKeyPressed(KEY_K))
		moveVectorPlayer2.y = -1;	
	else	
		moveVectorPlayer2.y = 0;
	
	if (IsKeyPressed(KEY_J))	
		moveVectorPlayer2.x = -1;	
	else if (IsKeyPressed(KEY_L))
		moveVectorPlayer2.x = 1;
	else	
		moveVectorPlayer2.x = 0;
	

	if (IsKeyPressed(KEY_U))
		player2->Rotate(defaultRotation * time->GetDeltaTime());

	if (IsKeyPressed(KEY_O))
		player2->Rotate(-defaultRotation * time->GetDeltaTime());

	if (IsKeyPressed(KEY_M))
		player2->Scale(defaultScale.x * time->GetDeltaTime(), defaultScale.y * time->GetDeltaTime());

	if (IsKeyPressed(KEY_N))
		player2->Scale(-defaultScale.x * time->GetDeltaTime(), -defaultScale.y * time->GetDeltaTime());

	#pragma endregion

	if (!moveVectorPlayer1.x == 0 || !moveVectorPlayer1.y == 0)
	{
		static_cast<Sprite*>(player1)->UpdateFrame();

		traslateX = moveVectorPlayer1.x * defaultTranslation.x * time->GetDeltaTime();
		traslateY = moveVectorPlayer1.y * defaultTranslation.y * time->GetDeltaTime();

		player1->Translate(traslateX, traslateY);
		checkCollisions(player1);
	}

	if (!moveVectorPlayer2.x == 0 || !moveVectorPlayer2.y == 0)
	{
		static_cast<Sprite*>(player2)->UpdateFrame();

		traslateX = moveVectorPlayer2.x * defaultTranslation.x * time->GetDeltaTime();
		traslateY = moveVectorPlayer2.y * defaultTranslation.y * time->GetDeltaTime();

		player2->Translate(traslateX, traslateY);
		checkCollisions(player2);
	}

	static_cast<Sprite*>(player1)->Draw();
	static_cast<Sprite*>(player2)->Draw();
}

void Game::checkCollisions(Entity2D* player)
{
	while (collisionManager->checkEntityToEntityCollision(player1, player2))
	{
		player->Translate(-traslateX, -traslateY);
	}

	while (collisionManager->checkEntityToWindowCollision(player, (Window*)window))
	{
		player->Translate(-traslateX, -traslateY);
	}
}