#include "BaseGame.h"
#include "Window.h"

BaseGame::BaseGame()
{
    isRunning = true;

    /* Initialize the library */
    if (!glfwInit())
        return;

    window = new Window(640, 480);
    Window* tempWindow = (Window*)window;

    ///* Create a windowed mode window and its OpenGL context */
    //window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
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
}

void BaseGame::Loop()
{
    Window* tempWindow = (Window*)window;

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    //glfwSwapBuffers((GLFWwindow*)tempWindow);
    glfwSwapBuffers((GLFWwindow*)tempWindow->GetGLFWPointer());

    /* Poll for and process events */
    tempWindow->ProcessWindowEvents();
}

bool BaseGame::IsRunning()
{
    return isRunning && !((Window*)window)->WindowShouldClose();
}