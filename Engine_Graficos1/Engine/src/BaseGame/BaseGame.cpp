#include <glfw/include/GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "BaseGame.h"
#include "Window/Window.h"
#include "RendererSingleton.h"
#include "Entity/Entity2D/Shape/Square/Square.h"

BaseGame::BaseGame()
{    
   
}

BaseGame::~BaseGame()
{
    glfwTerminate();
    delete window;
    delete renderer;
}

void BaseGame::OnStart(float height, float width, const char* programName)
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "ENGINE ERROR: GLFW Init failed" << std::endl;
        isRunning = false;
        return;
    }

    window = new Window(height, width, programName);
    Window* tempWindow = (Window*)window;

    renderer = new Renderer(tempWindow);


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

void BaseGame::Loop()
{   
    Window* tempWindow = (Window*)window;
    Renderer* tempRenderer = (Renderer*)renderer;
    
    //Init(); // Call children methods

    while (IsRunning())
    {
        /* Render here */
        tempRenderer->ClearScreen();

        Update(); // Call children methods

        /* Swap front and back buffers */
        tempRenderer->SwapWindowBuffers();

        /* Poll for and process events */
        tempWindow->ProcessWindowEvents();
    }
     
    DeInit(); // Call children methods
}

bool BaseGame::IsRunning()
{
    return isRunning && !((Window*)window)->WindowShouldClose();
}