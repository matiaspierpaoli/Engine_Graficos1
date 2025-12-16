#pragma once
#include <vector>
#include "../src/Frame/Frame.h"

struct Coord
{
	float x1;
	float y1;
	float x2;
	float y2;
};

class GraficosEngine_API Animation
{
private:
	std::vector<Coord> uCoords; //use only left U and right U
	std::vector<float> frameDurations;
	float timer;
	int currentFrame;

	float speedMultiplier;

public:
	Animation(float animLength, unsigned int textureWidth, unsigned int textureHeight, std::vector<Frame> frameData);
	~Animation();
	void Update();
	void Reset();

	void SetFrameDuration(int frameIndex, float duration);
	void SetSpeed(float speed);
	
	void AddFrame(Coord _uCoords);
	Coord GetCurrentFrame();
	Coord GetFrame(int frame);
};