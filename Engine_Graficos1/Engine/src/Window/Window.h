#pragma once

class Window
{
private:
	void* window;
	int height;
	int width;
	float zoomX;
	float zoomY;
	const char* programName;
	void CreateWindow();

public:
	Window(float height, float width, const char* programName, float zoomX, float zoomY);
	~Window();

	bool WindowExists();
	bool WindowShouldClose();
	void ProcessWindowEvents();
	void* GetGLFWPointer();
	float GetHeight();
	float GetWidth();
	float GetZoomX();
	float GetZoomY();
};
