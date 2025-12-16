#include "../src/Entity/Entity2D/Shape/Tile/Tile.h"

Tile::Tile(const std::string& path, int id, bool walkable) 
    : Sprite(path)
{
    _id = id;
    _walkable = walkable;
}

Tile::~Tile() {
}

bool Tile::IsWalkable() {
    return _walkable;
}

void Tile::SetWalkable(bool walkable) {
    _walkable = walkable;
}

int Tile::GetId() {
    return _id;
}