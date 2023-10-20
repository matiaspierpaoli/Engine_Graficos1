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
	defaultTranslation = 0.1f;

	float vertexCol1[4][4] = // White - no modification for sprites
	{
		 1.0f,  1.0f, 1.0f, 1.0f,
		 1.0f,  1.0f, 1.0f, 1.0f,
		 1.0f,  1.0f, 1.0f, 1.0f,
		 1.0f,  1.0f, 1.0f, 1.0f,
	};

	float vertexCol2[4][4] = // Green
	{
		 0.0f,  1.0f, 0.0f, 1.0f,
		 0.0f,  1.0f, 0.0f, 1.0f,
		 0.0f,  1.0f, 0.0f, 1.0f,
		 0.0f,  1.0f, 0.0f, 1.0f,
	};

	/*player1 = new Square(vertexCol1);
	player1->Scale(100, 100);
	player1->Translate(360, 360);

	player2 = new Square(vertexCol2);
	player2->Scale(100, 100);
	player2->Translate(100, 100);*/
	
	player1 = new Sprite("Worry-Lines-Autho.png", vertexCol1);
	player1->Scale(100, 100);
	player1->Translate(150, 200);

	player2 = new Sprite("Worry-Lines-Autho.png", vertexCol1);
	player2->Scale(150, 150);
	player2->Translate(300, 300);

}

void Game::DeInit()
{
	delete player1;
	delete player2;
}

void Game::Update()
{
	/*triangle->Scale(1, 1);
	triangle->Rotate(3);*/
	
	#pragma region Input
	// Player 1 input
	if (IsKeyPressed(KEY_W))
	{
		traslateX = 0.f;
		traslateY = defaultTranslation;
		player1->Translate(traslateX, traslateY * time->GetDeltaTime());
		checkCollisions(player1);
	}

	if (IsKeyPressed(KEY_S))
	{
		traslateX = 0.f;
		traslateY = -defaultTranslation;
		player1->Translate(traslateX, traslateY * time->GetDeltaTime());
		checkCollisions(player1);
	}

	if (IsKeyPressed(KEY_A))
	{
		traslateX = -defaultTranslation;
		traslateY = 0.f;
		player1->Translate(traslateX * time->GetDeltaTime(), traslateY);
		checkCollisions(player1);
	}

	if (IsKeyPressed(KEY_D))
	{
		traslateX = defaultTranslation;
		traslateY = 0.f;
		player1->Translate(traslateX * time->GetDeltaTime(), traslateY);
		checkCollisions(player1);
	}

	if (IsKeyPressed(KEY_Q))
		player1->Rotate(0.1f * time->GetDeltaTime());

	if (IsKeyPressed(KEY_E))	
		player1->Rotate(-0.1f * time->GetDeltaTime());

	if (IsKeyPressed(KEY_X))	
		player1->Scale(0.2 * time->GetDeltaTime(), 0.2 * time->GetDeltaTime());

	if (IsKeyPressed(KEY_Z))	
		player1->Scale(-0.2 * time->GetDeltaTime(), -0.2 * time->GetDeltaTime());	

	// Player 2 input
	if (IsKeyPressed(KEY_I))
	{
		traslateX = 0.f;
		traslateY = defaultTranslation;
		player2->Translate(traslateX, traslateY * time->GetDeltaTime());
		checkCollisions(player2);
	}

	if (IsKeyPressed(KEY_K))
	{
		traslateX = 0.f;
		traslateY = -defaultTranslation;
		player2->Translate(traslateX, traslateY * time->GetDeltaTime());
		checkCollisions(player2);
	}

	if (IsKeyPressed(KEY_J))
	{
		traslateX = -defaultTranslation;
		traslateY = 0.f;
		player2->Translate(traslateX * time->GetDeltaTime(), traslateY);
		checkCollisions(player2);
	}

	if (IsKeyPressed(KEY_L))
	{
		traslateX = defaultTranslation;
		traslateY = 0.f;
		player2->Translate(traslateX * time->GetDeltaTime(), traslateY);
		checkCollisions(player2);
	}

	if (IsKeyPressed(KEY_U))
		player2->Rotate(0.1f * time->GetDeltaTime());

	if (IsKeyPressed(KEY_O))
		player2->Rotate(-0.1f * time->GetDeltaTime());

	if (IsKeyPressed(KEY_M))
		player2->Scale(0.2 * time->GetDeltaTime(), 0.2 * time->GetDeltaTime());

	if (IsKeyPressed(KEY_N))
		player2->Scale(-0.2 * time->GetDeltaTime(), -0.2 * time->GetDeltaTime());

	#pragma endregion

	/*static_cast<Square*>(player1)->Draw();
	static_cast<Square*>(player2)->Draw();*/

	static_cast<Sprite*>(player1)->Draw();
	static_cast<Sprite*>(player2)->Draw();
}

void Game::checkCollisions(Entity2D* player)
{
	while (collisionManager->checkEntityToEntityCollision(player1, player2))
	{
		//std::cout << "colission\n";
		player->Translate(-traslateX, -traslateY);
	}

	while (collisionManager->checkEntityToWindowCollision(player, (Window*)window))
	{
		player->Translate(-traslateX, -traslateY);
	}
}