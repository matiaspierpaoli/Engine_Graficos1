#pragma once
#include <string>
#include "Entity/Entity2D/Entity2D.h"
#include "Exports.h"

class GraficosEngine_API Sprite : public Entity2D
{
private:
	unsigned int mRendererID;
	unsigned int imageID;
	std::string mFilePath;
	unsigned char* mLocalBuffer;
	int mWidth;
	int mHeight;
	int mBPP;
	float vertices[4][8];

public:
	Sprite(const std::string& path, float vertexCol[4][4]);
	~Sprite();

	void Bind(unsigned int slot = 0) const;
	void Unbind();

	int GetWidth();
	int GetHeight();

	void Draw();
};
