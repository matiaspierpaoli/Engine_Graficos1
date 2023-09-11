#include "Game.h"

Game::Game()
{
	//triangle = new Triangle();
	square = new Square();
}

Game::~Game()
{
	//delete triangle;
	delete square;
}

bool Game::IsRunning()
{
	return BaseGame::IsRunning();
}

void Game::Loop()
{
	BaseGame::Loop();
}

void Game::Draw()
{
	//triangle->Draw();
	square->Draw();
}