#pragma once
#include "Entity/Entity2D/Shape/Shape.h"

class  __declspec(dllexport) Square : public Shape
{
public:
	Square();
	~Square();

	void Draw() override;
};
