#include "Animation.h"
#include "BaseGame/BaseGame.h"
#include "TimeSingleton.h"

#include <iostream>

Animation::Animation(float animLength, unsigned int textureWidth, unsigned int textureHeight, std::vector<Frame> frameData)
{
	currentFrame = 0;
	timer = 0;
	speedMultiplier = 1.0f;

	float defaultFrameDuration = animLength / (float)frameData.size();
	for (unsigned int i = 0; i < frameData.size(); i++)
	{
		//Calculate left and right of frame
		Coord frameCoords;
		frameCoords.x1 = (float)frameData[i].GetLeftX() / textureWidth;
		frameCoords.y1 = (float)(frameData[i].GetTopY()) / textureHeight;

		frameCoords.x2 = (float)frameData[i].GetRightX() / textureWidth;
		frameCoords.y2 = (float)(frameData[i].GetBotY()) / textureHeight;

		//Send frame U coordinates to the vector
		AddFrame(frameCoords);
		frameDurations.push_back(defaultFrameDuration);
	}
}

Animation::~Animation()
{
}

void Animation::Update()
{
	timer += TimeSingleton::GetTime()->GetDeltaTime()* speedMultiplier;

	while (timer >= frameDurations[currentFrame]) {
		timer -= frameDurations[currentFrame];
		currentFrame++;

		if (currentFrame >= uCoords.size()) {
			currentFrame = 0;
		}
	}
}

void Animation::Reset()
{
	currentFrame = 0;
	timer = 0.0f;
}


void Animation::SetFrameDuration(int frameIndex, float duration)
{
	if (frameIndex >= 0 && frameIndex < frameDurations.size()) {
		frameDurations[frameIndex] = duration;
	}
}

void Animation::SetSpeed(float speed)
{
	speedMultiplier = speed;
}

void Animation::AddFrame(Coord _uCoords)
{
	uCoords.push_back(_uCoords);
}

Coord Animation::GetCurrentFrame()
{
	return uCoords[currentFrame];
}

Coord Animation::GetFrame(int frame)
{
	return uCoords[frame];
}