#pragma once

class Entity
{
public:
	Entity();
	~Entity();

	unsigned int* vBuffer;
	unsigned int* iBuffer;

	virtual void Draw();
};

