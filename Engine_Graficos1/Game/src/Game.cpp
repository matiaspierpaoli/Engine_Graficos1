#include "Game.h"

Game::Game()
{
	triangle = new Triangle();
	//square = new Square();
	
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
	triangle->Rotate(0.2);
	triangle->Scale(0.01, 0.01);
}

void Game::Draw()
{
	triangle->Draw();
	//square->Draw();
}