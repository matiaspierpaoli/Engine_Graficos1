#pragma once
#include "Entity/Entity2D/Shape/Tile/Tile.h"
#include "Exports.h"
#include <vector>
#include <string>


class GraficosEngine_API TileMap
{
    private:
    // 3 dimentional tilemap
    // Layer   < Row      < Column     < Tile* > > >
    std::vector<std::vector<std::vector<Tile*>>> _mapLayers;

	Entity2D* debugSquare;
	
    std::string _imagePath;
    float _mapWidth;  
    float _mapHeight; 
    float _tileWidth; 
    float _tileHeight;
	
    int _tilesetWidth; 
    int _tilesetHeight;

    public:
    TileMap();
    ~TileMap();

    bool ImportTileMap(std::string filePath);
    void Draw(bool shouldDrawCollisionSquares);
	void CheckCollision(Entity2D* object, float* velocityY, bool* isGrounded);
   

    private:
    void ClearMap();
    void CreateTile(int layerIndex, int id, int x, int y, bool walkable);
};