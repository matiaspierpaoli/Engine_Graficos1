#pragma once

class __declspec(dllexport) BaseGame
{
private:
	void* window;
	void* renderer;
	bool isRunning = true;

public:
	BaseGame();
	~BaseGame();

	void Loop();
	bool IsRunning();

	virtual void Draw();
};