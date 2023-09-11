#pragma once

#pragma once
#include "Entity/Entity2D/Shape/Shape.h"

class  __declspec(dllexport) Triangle : public Shape
{
public:
	Triangle();
	~Triangle();

	void Draw();
};

