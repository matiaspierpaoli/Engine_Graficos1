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

	sprite1 = new Sprite("Worry-Lines-Autho.png");
	sprite1->Scale(100, 100);
	sprite1->Translate(360, 360);

	sprite2 = new Sprite("Worry-Lines-Autho.png");
	sprite2->Scale(100, 100);
	sprite2->Translate(100, 100);
}

void Game::DeInit()
{
	delete sprite1;
	delete sprite2;

}

void Game::Update()
{
	/*triangle->Scale(1, 1);
	triangle->Rotate(3);*/
	
	if (IsKeyPressed(KEY_W)) 
	{
		sprite1->Translate(0, 0.1f * time->GetDeltaTime());
	}

	if (IsKeyPressed(KEY_S)) 
	{
		sprite1->Translate(0, -0.1f * time->GetDeltaTime());
	}

	if (IsKeyPressed(KEY_A)) 
	{
		sprite1->Translate(-0.1 * time->GetDeltaTime(), 0);
	}
	
	if (IsKeyPressed(KEY_D))
	{
		sprite1->Translate(0.1 * time->GetDeltaTime(), 0);
	}

	if (IsKeyPressed(KEY_Q))
	{
		sprite1->Rotate(0.3f * time->GetDeltaTime());
	}

	if (IsKeyPressed(KEY_E))
	{
		sprite1->Rotate(-0.3f * time->GetDeltaTime());
	}

	if (IsKeyPressed(KEY_Z))
	{
		sprite1->Scale(2 * time->GetDeltaTime(), 2 * time->GetDeltaTime());
	}

	if (IsKeyPressed(KEY_X))
	{
		sprite1->Scale(-2 * time->GetDeltaTime(), -2 * time->GetDeltaTime());
	}

	sprite1->Draw();
	sprite2->Draw();
}