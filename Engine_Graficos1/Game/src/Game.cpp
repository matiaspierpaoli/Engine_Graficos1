#include "Game.h"

Game::Game()
{
	triangle = new Triangle();

	triangle->Translate(320, 480);
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
	triangle->Scale(1.0, 1.0);
	triangle->Translate(0.0, -1.0);
}

void Game::Draw()
{
	triangle->Draw();
}