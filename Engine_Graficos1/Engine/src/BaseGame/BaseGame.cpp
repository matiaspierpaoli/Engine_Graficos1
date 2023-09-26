#include "BaseGame.h"
#include "Window/Window.h"
#include "RendererSingleton.h"
//#include "Renderer/Renderer.h"

#include <glfw/include/GLFW/glfw3.h>
#include <iostream>

#include "Entity/Entity2D/Shape/Square/Square.h"

BaseGame::BaseGame()
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "ENGINE ERROR: GLFW Init failed" << std::endl;
        isRunning = false;
        return;
    }

    window = new Window(480, 480);
    Window* tempWindow = (Window*)window;

    //renderer = new Renderer(tempWindow);
    

    if (!tempWindow->WindowExists())
    {
        std::cout << "ENGINE ERROR: Window Init failed" << std::endl;
        isRunning = false;
        glfwTerminate();
        return;
    }

    RendererSingleton::SetRenderer(new Renderer(tempWindow));
    renderer = RendererSingleton::GetRenderer();
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
    
    /*tempRenderer->Draw();*/

    Draw();

    /* Swap front and back buffers */
    tempRenderer->SwapWindowBuffers();

    /* Poll for and process events */
    tempWindow->ProcessWindowEvents();
}

bool BaseGame::IsRunning()
{
    return isRunning && !((Window*)window)->WindowShouldClose();
}

void BaseGame::Draw()
{

}