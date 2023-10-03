#pragma once
#include "Exports.h"

class GraficosEngine_API BaseGame
{
private:
	void* window;
	void* renderer;
	bool isRunning = true;

public:
	BaseGame();
	~BaseGame();

	void OnStart(float height, float width, const char* programName);

	void Loop();
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void DeInit() = 0;
	bool IsRunning();
};