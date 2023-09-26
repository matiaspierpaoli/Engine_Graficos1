#include "Game.h"

Game::Game()
{
	triangle = new Triangle();
	//triangle->Translate(300, 300);
	triangle->Scale(100, 100);
}

Game::~Game()
{
	delete triangle;
}

bool Game::IsRunning()
{
	return BaseGame::IsRunning();
}

void Game::Loop()
{
	BaseGame::Loop();

	if (triangle->GetTranslation().x <= 480 && triangle->GetTranslation().y <= 480)
	{
		triangle->Rotate(3);
		triangle->Translate(5, 5);
	}
}

void Game::Draw()
{
	triangle->Draw();
}