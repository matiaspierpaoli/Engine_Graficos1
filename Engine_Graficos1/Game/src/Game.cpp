#include "Game.h"

Game::Game()
{
	triangle = new Triangle();
	//square = new Square();

	//triangle->Scale(100, 100);
	
}

Game::~Game()
{
	delete triangle;
	//delete square;
}

bool Game::IsRunning()
{
	return BaseGame::IsRunning();
}

void Game::Loop()
{
	BaseGame::Loop();
	triangle->Scale(0.01, 0.01);
	triangle->Rotate(3);
}

void Game::Draw()
{
	triangle->Draw();
	//square->Draw();
}