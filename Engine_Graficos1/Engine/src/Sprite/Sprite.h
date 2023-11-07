#pragma once
#include <string>
#include "Entity/Entity2D/Entity2D.h"
#include "Exports.h"
#include "Animation/Animation.h"
#include "Frame/Frame.h"

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
	float vertices[4][4];
	Animation* anim;
	unsigned int spriteQty;

	void ChangeSprite(float leftU, float rightX);
	void Bind(unsigned int slot = 0) const;
	void Unbind();

public:
	Sprite(const std::string& path);
	Sprite(const std::string& path, float vertexCol[4][4]);
	Sprite(const std::string& path, int spriteQuantity, int spriteNumber);
	Sprite(const std::string& path, int frameQuantity, int spriteWidth, int spriteHeight, std::vector<Frame>& frameData);
	~Sprite();

	unsigned int GetImageID();
	inline int GetSpriteQty() const { return spriteQty; }
	inline int GetImgWidth() const { return mWidth; }
	inline int GetImgHeight() const { return mHeight; }
	inline int GetWidth()const { return mWidth / spriteQty; }
	inline int GetHeight()const { return mHeight; }

	void ChangeSprite(int spriteQuantity, int spriteNumber);
	void SetAnim(Animation* _anim);
	void UpdateFrame();

	void Draw();
};
