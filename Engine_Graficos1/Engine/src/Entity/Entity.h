#pragma once
#include "Vector2.h"

class __declspec(dllexport) Entity
{
private:
	Vector2 translation;
	float rotation;
	Vector2 scale;

public:
	Entity();
	~Entity();

	unsigned int* vBuffer;
	unsigned int* iBuffer;
	unsigned int modelId;

	void Translate(float x, float y);
	void Rotate(float angle);
	void Scale(float x, float y);

	Vector2 GetTranslation();
	float GetRotation();
	Vector2 GetScale();

	void UpdateModel(bool isModelCreated);
};

