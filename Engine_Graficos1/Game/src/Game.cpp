#include "Game.h"

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
	player1->Translate(100, 100);

	player2 = new Sprite("Worry-Lines-Autho.png", vertexCol1);
	player2->Scale(100, 100);
	player2->Translate(360, 360);

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
		player1->Translate(0, 0.1f * time->GetDeltaTime());
	
	if (IsKeyPressed(KEY_S)) 	
		player1->Translate(0, -0.1f * time->GetDeltaTime());
	
	if (IsKeyPressed(KEY_A)) 	
		player1->Translate(-0.1 * time->GetDeltaTime(), 0);
		
	if (IsKeyPressed(KEY_D))	
		player1->Translate(0.1 * time->GetDeltaTime(), 0);	

	if (IsKeyPressed(KEY_Q))	
		player1->Rotate(0.3f * time->GetDeltaTime());	

	if (IsKeyPressed(KEY_E))	
		player1->Rotate(-0.3f * time->GetDeltaTime());

	if (IsKeyPressed(KEY_X))	
		player1->Scale(2 * time->GetDeltaTime(), 2 * time->GetDeltaTime());

	if (IsKeyPressed(KEY_Z))	
		player1->Scale(-2 * time->GetDeltaTime(), -2 * time->GetDeltaTime());	

	// Player 2 input
	if (IsKeyPressed(KEY_I))
		player2->Translate(0, 0.1f * time->GetDeltaTime());

	if (IsKeyPressed(KEY_K))
		player2->Translate(0, -0.1f * time->GetDeltaTime());

	if (IsKeyPressed(KEY_J))
		player2->Translate(-0.1 * time->GetDeltaTime(), 0);

	if (IsKeyPressed(KEY_L))
		player2->Translate(0.1 * time->GetDeltaTime(), 0);

	if (IsKeyPressed(KEY_U))
		player2->Rotate(0.3f * time->GetDeltaTime());

	if (IsKeyPressed(KEY_O))
		player2->Rotate(-0.3f * time->GetDeltaTime());

	if (IsKeyPressed(KEY_M))
		player2->Scale(2 * time->GetDeltaTime(), 2 * time->GetDeltaTime());

	if (IsKeyPressed(KEY_N))
		player2->Scale(-2 * time->GetDeltaTime(), -2 * time->GetDeltaTime());

	#pragma endregion

	/*static_cast<Square*>(player1)->Draw();
	static_cast<Square*>(player2)->Draw();*/

	static_cast<Sprite*>(player1)->Draw();
	static_cast<Sprite*>(player2)->Draw();
}