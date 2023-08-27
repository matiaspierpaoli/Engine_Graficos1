#include "BaseGame.h"
#include "Window.h"
#include "Renderer.h"

BaseGame::BaseGame()
{
    isRunning = true;

    /* Initialize the library */
    if (!glfwInit())
        return;

    window = new Window(640, 480);
    Window* tempWindow = (Window*)window;

    renderer = new Renderer(tempWindow);
    

    if (!tempWindow->WindowExists())
    {
        isRunning = false;
        glfwTerminate();
        return;
    }
}

BaseGame::~BaseGame()
{
    glfwTerminate();
    delete window;
    delete renderer;
}

void BaseGame::Loop()
{
    Window* tempWindow = (Window*)window;
    Renderer* tempRenderer = (Renderer*)renderer;

    /* Render here */
    tempRenderer->ClearScreen();
    tempRenderer->Draw();
    /* Swap front and back buffers */
    tempRenderer->SwapWindowBuffers();

    /* Poll for and process events */
    tempWindow->ProcessWindowEvents();
}

bool BaseGame::IsRunning()
{
    return isRunning && !((Window*)window)->WindowShouldClose();
}