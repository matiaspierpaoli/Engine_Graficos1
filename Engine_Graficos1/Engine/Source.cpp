#include "BaseGame.h"

int main(void)
{
    BaseGame* baseGame = new BaseGame();
    
    while (baseGame->IsRunning())
    {
        baseGame->Loop();
    }

    delete baseGame;

    return 0;
}