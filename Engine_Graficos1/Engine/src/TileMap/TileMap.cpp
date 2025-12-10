#include "TileMap/TileMap.h"
#include <iostream>
#include <cmath>
#include "../libs/tinyxml2/tinyxml2.h"

TileMap::TileMap() {
	_mapWidth = 0;
	_mapHeight = 0;
	_tileWidth = 0;
	_tileHeight = 0;
	_tilesetWidth = 0;
	_tilesetHeight = 0;
}

TileMap::~TileMap() {
	ClearMap();
}

void TileMap::ClearMap() {
	for (size_t i = 0; i < _mapLayers.size(); i++) {          // Axis 1: Layer
		for (size_t y = 0; y < _mapLayers[i].size(); y++) {   // Axis 2: Row (Y)
			for (size_t x = 0; x < _mapLayers[i][y].size(); x++) { // Axis 3: Column (X)
				if (_mapLayers[i][y][x] != nullptr) {
					delete _mapLayers[i][y][x];
				}
			}
		}
	}
	_mapLayers.clear();
}

void TileMap::Draw() {
	for (size_t i = 0; i < _mapLayers.size(); i++) {           // Axis 1: Layer
		for (size_t y = 0; y < _mapLayers[i].size(); y++) {    // Axis 2: Row (Y)
			for (size_t x = 0; x < _mapLayers[i][y].size(); x++) { // Axis 3: Column (X)
				if (_mapLayers[i][y][x] != nullptr) {
					_mapLayers[i][y][x]->Draw();
				}
			}
		}
	}
}

bool TileMap::ImportTileMap(std::string filePath) {
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLError error = doc.LoadFile(filePath.c_str());

	if (error != tinyxml2::XML_SUCCESS) return false;

	tinyxml2::XMLElement* mapNode = doc.FirstChildElement("map");
	if (!mapNode) return false;

	_mapWidth = mapNode->FloatAttribute("width");
	_mapHeight = mapNode->FloatAttribute("height");
	_tileWidth = mapNode->FloatAttribute("tilewidth");
	_tileHeight = mapNode->FloatAttribute("tileheight");

	// Load Tileset
	tinyxml2::XMLElement* pTileset = mapNode->FirstChildElement("tileset");
	if (!pTileset) return false;
	
	// Image creation from tileset
	tinyxml2::XMLElement* imageNode = pTileset->FirstChildElement("image");
	if(imageNode) {
		std::string source = imageNode->Attribute("source");
		size_t lastSlash = source.find_last_of("/\\");
		std::string fileName = source.substr(lastSlash + 1);
		_imagePath = "res/Dungeon/" + fileName;
		_tilesetWidth = imageNode->IntAttribute("width");
		_tilesetHeight = imageNode->IntAttribute("height");
	}

	// ---------------------------------------------------------
	// Multiple Layer Logic
	// ---------------------------------------------------------
	
	// Iterate through related layer elements
	tinyxml2::XMLElement* pLayer = mapNode->FirstChildElement("layer");
	
	int layerIndex = 0;

	while (pLayer) {
		// Detect if layer isSolid
        // By default assume layer is not solid but wakable
        bool layerIsSolid = false; 

        // Look for element <properties> inside layer
        tinyxml2::XMLElement* pProperties = pLayer->FirstChildElement("properties");
        
        if (pProperties) {
            // If there are properties, iterate looking for "isSolid"
            tinyxml2::XMLElement* pProperty = pProperties->FirstChildElement("property");
            while (pProperty) {
                const char* propName = pProperty->Attribute("name");
                
                // Compare if name is "isSolid"
                if (propName && std::string(propName) == "isSolid") {
                    // Reed boolean value
                    layerIsSolid = pProperty->BoolAttribute("value");
                    break; // With value found, exit internal while
                }
                
                pProperty = pProperty->NextSiblingElement("property");
            }
        }

        // -------------------------------------------------------

        // Create space for new layer
        _mapLayers.push_back(std::vector<std::vector<Tile*>>());
        _mapLayers[layerIndex].resize(_mapHeight);
        for (int i = 0; i < _mapHeight; i++) {
            _mapLayers[layerIndex][i].resize(_mapWidth, nullptr);
        }

        // Read data from this layer
        tinyxml2::XMLElement* pData = pLayer->FirstChildElement("data");
        if (pData) {
            int x = 0;
            int y = 0;

            for (tinyxml2::XMLElement* pTile = pData->FirstChildElement("tile"); pTile != NULL; pTile = pTile->NextSiblingElement("tile")) {
                unsigned int gid = pTile->IntAttribute("gid");

                if (gid > 0) {
                    // If layerIsSolid is true, isWalkable must be false.
                    // If layerIsSolid is false, isWalkable must be true.
                    // This is the reason for "!layerIsSolid" below
                    CreateTile(layerIndex, gid - 1, x, y, !layerIsSolid); 
                }

                x++;
                if (x >= _mapWidth) {
                    x = 0;
                    y++;
                }
            }
        }

        // Next layer in XML file
        pLayer = pLayer->NextSiblingElement("layer");
        layerIndex++;
	}

	return true;
}

void TileMap::CreateTile(int layerIndex, int id, int x, int y, bool walkable) {
	Tile* newTile = new Tile(_imagePath, id + 1, walkable);
	
	// Calculate UV Coords
	// Tiled sorts from left to right, top to bottom.
	int columns = _tilesetWidth / (int)_tileWidth;
	
	int col = id % columns;
	int row = id / columns;

	float u1 = (col * _tileWidth) / (float)_tilesetWidth;
	float v1 = (row * _tileHeight) / (float)_tilesetHeight;
	float u2 = ((col + 1) * _tileWidth) / (float)_tilesetWidth;
	float v2 = ((row + 1) * _tileHeight) / (float)_tilesetHeight;

	// Inverting V
	// Minding stbi_set_flip_vertically_on_load(1); in Renderer.cpp:
	// UV (0,0) from texture is bottom left
	// But Tiled has (0,0) top left so Invert V.
	
	float v1_gl = 1.0f - v2; 
	float v2_gl = 1.0f - v1;

	Coord uvCoords;
	uvCoords.x1 = u1; uvCoords.y1 = v1_gl;
	uvCoords.x2 = u2; uvCoords.y2 = v2_gl;

	// Update sprite so it shows only this piece
	newTile->ChangeSprite(uvCoords);

	// Position in world
	newTile->Scale(_tileWidth, _tileHeight);
	
	// In this engine, sprite entity (0,0) is in the center.
	// Knowing Tiled uses coords Top-Left.
	// Adjust to center tile:

	// Half right
	float posX = (x * _tileWidth) + (_tileWidth / 2.0f);
	// Inverint Y, half up
	float posY = (_mapHeight * _tileHeight) - (y * _tileHeight) - (_tileHeight / 2.0f);

	newTile->Translate(posX, posY);

	if (x == 0 && y == 0 && layerIndex == 0) {
		std::cout << "--- DIAGNOSTICO TILEMAP ---" << std::endl;
		std::cout << "Tile Size (XML): " << _tileWidth << " x " << _tileHeight << std::endl;
		std::cout << "Map Height (Tiles): " << _mapHeight << std::endl;
		std::cout << "Posicion Calculada (X, Y): " << posX << ", " << posY << std::endl;
		std::cout << "Textura ID: " << newTile->GetImageID() << std::endl;
		std::cout << "---------------------------" << std::endl;
	}
	
	// Store in grid
	_mapLayers[layerIndex][y][x] = newTile;
}

