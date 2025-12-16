#pragma once
#include "../src/Vector2.h"
#include "../src/Exports.h"

class GraficosEngine_API Entity
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
	
	void SetTranslation(float x, float y);
	void SetRotation(float angle);
	void SetScale(float x, float y);

	Vector2 GetTranslation();
	float GetRotation();
	Vector2 GetScale();

	void UpdateModel(bool isModelCreated);
};

