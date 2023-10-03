#include "Game.h"

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
	//delete triangle;
	delete square;
	delete square2;
	/*delete triangle;
	delete triangle2;*/
}

void Game::Update()
{
	/*triangle->Scale(1, 1);
	triangle->Rotate(3);*/
	
	square->Draw();
	square2->Draw();
	/*triangle->Draw();
	triangle2->Draw();*/

	//triangle->Draw();
}