#pragma once
#include "Exports.h"

class  GraficosEngine_API Frame
{
private:
	float leftU;
	float rightU;
	float topV;
	float botV;

public:
	Frame(int mleftU, int mrightU, int mtopV, int mbotV) { leftU  = mleftU;
														   rightU = mrightU;
														   topV   = mtopV;
														   botV   = mbotV;
	}

	float GetLeftU()  { return leftU; }
	float GetRightU() { return rightU; }
	float GetTopV()   { return topV; }
	float GetBotV()   { return botV; }
};