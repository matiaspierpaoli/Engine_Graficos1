#pragma once

class Window
{
private:
	void* window;
	int height;
	int width;
	void CreateWindow();

public:
	Window(float height, float width);
	~Window();

	bool WindowExists();
	bool WindowShouldClose();
	void ProcessWindowEvents();
	void* GetGLFWPointer();
	float GetHeight();
	float GetWidth();
};
