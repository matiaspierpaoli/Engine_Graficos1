#include "BaseGame.h"

int main(void)
{
    BaseGame* baseGame = new BaseGame();
    baseGame->Loop();
    delete baseGame;

    return 0;
}