#pragma once

class __declspec(dllexport) Entity
{
public:
	Entity();
	~Entity();

	unsigned int* vBuffer;
	unsigned int* iBuffer;
};

