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
    void Draw();
   

    private:
    void CreateTile(int layerIndex, int id, int x, int y, bool walkable);
    void ClearMap();
};