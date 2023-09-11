#pragma once

class __declspec(dllexport) BaseGame
{
private:
	void* window;
	void* renderer;
	bool isRunning = true;

	//Entity* square;
	//Entity* triangle;

public:
	BaseGame();
	~BaseGame();

	void Loop();
	bool IsRunning();
};