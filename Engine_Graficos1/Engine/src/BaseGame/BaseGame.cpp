#include "BaseGame.h"
#include "Window/Window.h"
//#include "Renderer/Renderer.h"
#include "RendererSingleton.h"

BaseGame::BaseGame()
{
    isRunning = true;

    /* Initialize the library */
    if (!glfwInit())
        return;

    window = new Window(640, 480);
    Window* tempWindow = (Window*)window;

    //renderer = new Renderer(tempWindow);
    

    if (!tempWindow->WindowExists())
    {
        isRunning = false;
        glfwTerminate();
        return;
    }

    RendererSingleton::SetRenderer(new Renderer(tempWindow));
    renderer = RendererSingleton::GetRenderer();

    square = new Square();
    triangle = new Triangle();
}

BaseGame::~BaseGame()
{
    glfwTerminate();
    delete window;
    delete renderer;
    
    delete square;
    delete triangle;
}

void BaseGame::Loop()
{
    Window* tempWindow = (Window*)window;
    Renderer* tempRenderer = (Renderer*)renderer;

    /* Render here */
    tempRenderer->ClearScreen();
    
    /*tempRenderer->Draw();*/

    //square->Draw();
    triangle->Draw();

    /* Swap front and back buffers */
    tempRenderer->SwapWindowBuffers();

    /* Poll for and process events */
    tempWindow->ProcessWindowEvents();
}

bool BaseGame::IsRunning()
{
    return isRunning && !((Window*)window)->WindowShouldClose();
}