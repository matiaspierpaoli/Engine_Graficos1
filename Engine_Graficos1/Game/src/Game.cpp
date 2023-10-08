#include "Game.h"

#pragma region keyCodes

#define KEY_W 87
#define KEY_A 65
#define KEY_S 83
#define KEY_D 68

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

	/*triangle = new Triangle();
	triangle->Scale(100, 100);
	triangle->Translate(360, 360);*/

	float vertexCol1[4][4] = 
	{
		 0.0f,  1.0f, 0.0f, 1.0f,
		 0.0f,  1.0f, 0.0f, 1.0f,
		 0.0f,  1.0f, 0.0f, 1.0f,
		 0.0f,  1.0f, 0.0f, 1.0f,
	};

	square = new Square(vertexCol1);
	square->Scale(100, 100);
	square->Translate(120, 120);


	float vertexCol2[4][4] =
	{
		 0.0f,  0.0f, 1.0f, 1.0f,
		 0.0f,  0.0f, 1.0f, 1.0f,
		 0.0f,  0.0f, 1.0f, 1.0f,
		 0.0f,  0.0f, 1.0f, 1.0f,
	};

	square2 = new Square(vertexCol2);
	square2->Scale(100, 100);
	square2->Translate(340, 340);

	/*triangle = new Triangle();
	triangle->Scale(100, 100);
	triangle->Translate(240, 240);

	triangle2 = new Triangle();
	triangle2->Scale(100, 100);
	triangle2->Translate(360, 360);*/
}

void Game::DeInit()
{
	delete square;
	delete square2;
}

void Game::Update()
{
	/*triangle->Scale(1, 1);
	triangle->Rotate(3);*/
	
	if (IsKeyPressed(KEY_W)) 
	{
		square->Translate(0, 0.1f * time->GetDeltaTime());
	}

	if (IsKeyPressed(KEY_S)) 
	{
		square->Translate(0, -0.1f * time->GetDeltaTime());
	}

	if (IsKeyPressed(KEY_A)) 
	{
		square->Translate(-0.1 * time->GetDeltaTime(), 0);
	}
	
	if (IsKeyPressed(KEY_D))
	{
		square->Translate(0.1 * time->GetDeltaTime(), 0);
	}

	square->Draw();
	square2->Draw();
}