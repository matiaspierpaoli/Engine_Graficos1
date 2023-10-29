#include "Animation.h"
#include "BaseGame/BaseGame.h"
#include "TimeSingleton.h"

Animation::Animation(float animLength, unsigned int framesQty)
{
	length = animLength;
	currentFrame = 0;
	timer = 0;

	for (unsigned int i = 0; i < framesQty; i++)
	{
		//Calculate left and right of frame
		Vector2 frameCoords;
		frameCoords.x = (float)i / framesQty;
		frameCoords.y = (float)(i + 1) / framesQty;

		//Send frame U coordinates to the vector
		AddFrame(frameCoords);
	}
}

Animation::~Animation()
{
}

void Animation::Update()
{
	timer += TimeSingleton::GetTime()->GetDeltaTime();

	while (timer >= length) {
		timer -= length;
	}

	float frameLength = length / uCoords.size();
	currentFrame = static_cast<int>(timer / frameLength);
}

void Animation::AddFrame(Vector2 _uCoords)
{
	uCoords.push_back(_uCoords);
}

void Animation::SetDuration(float _length)
{
	length = _length;
}

Vector2 Animation::GetCurrentFrame()
{
	return uCoords[currentFrame];
}

Vector2 Animation::GetFrame(int frame)
{
	return uCoords[frame];
}