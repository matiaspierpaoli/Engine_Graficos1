#include "Game.h"

Game::Game()
{
	
}

Game::~Game()
{

}

void Game::Init()
{
	OnStart(480, 480, "Hola");

	triangle = new Triangle();
	triangle->Scale(100, 100);
	triangle->Translate(240, 240);
}

void Game::DeInit()
{
	delete triangle;
}

void Game::Update()
{
	triangle->Scale(1, 1);
	triangle->Rotate(3);
	
	
	triangle->Draw();
}