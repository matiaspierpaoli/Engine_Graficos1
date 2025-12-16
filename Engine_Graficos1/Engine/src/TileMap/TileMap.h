#pragma once
#include "Entity/Entity2D/Shape/Tile/Tile.h"
#include "Exports.h"
#include <vector>
#include <string>
#include "../Collisions/CollisionManager.h"

class GraficosEngine_API TileMap
{
    private:
    // 3 dimentional tilemap
    // Layer   < Row      < Column     < Tile* > > >
    std::vector<std::vector<std::vector<Tile*>>> _mapLayers;
    std::vector<std::string> _layerNames;

	std::vector<float> _layerOffsetX;
	std::vector<float> _layerOffsetY;

	Entity2D* debugSquare;
	
    std::string _imagePath;
    float _mapWidth;  
    float _mapHeight; 
    float _tileWidth; 
    float _tileHeight;
	
    int _tilesetWidth; 
    int _tilesetHeight;

	CollisionManager _collisionManager;
	
    public:
    TileMap(CollisionManager collisionManager);
    ~TileMap();

    bool ImportTileMap(std::string filePath);
    void Draw(bool shouldDrawCollisionSquares);
	void DrawLayers(size_t start, size_t endInclusive, bool shouldDrawCollisionSquares); // inclusive
	void CheckCollision(Entity2D* object, float* velocityY, bool* isGrounded);
    int FindLayerIndex(const std::string& name) const;

    float GetMapWidth()  const { return _mapWidth; } 
	float GetTileWidth() const { return _tileWidth; }
	float GetWorldWidth() const { return _mapWidth * _tileWidth; }
	int GetLayerCount() const;
	
    private:
    void ClearMap();
    void CreateTile(int layerIndex, int id, int x, int y, bool walkable);
};