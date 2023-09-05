#include "Game.h"

int main()
{
	Game* game = new Game();

	while (game->IsRunning())
	{
		game->Loop();
	}

	delete game;
}