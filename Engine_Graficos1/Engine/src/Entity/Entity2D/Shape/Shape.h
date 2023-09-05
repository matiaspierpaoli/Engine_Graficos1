#pragma once
#include "Entity/Entity2D/Entity2D.h"

class  __declspec(dllexport) Shape : public Entity2D
{
public:
	Shape();
	~Shape();

	void Draw() override;
};
