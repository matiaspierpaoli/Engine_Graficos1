#pragma once
#include "../src/Sprite/Sprite.h"
#include "../src/Exports.h"

class GraficosEngine_API Tile : public Sprite
{
    private:
    int _id;
    bool _walkable;

    public:
    Tile(const std::string& path, int id, bool walkable);
    ~Tile();

    bool IsWalkable();
    void SetWalkable(bool walkable);
    int GetId();
};