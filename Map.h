//
// Created by ondra on 06/12/2025.
//

#ifndef ZOO_PROJEKT_MAP_H
#define ZOO_PROJEKT_MAP_H
#include <vector>

#include "Tile.h"


class Map {
private:
    std::vector<std::vector<Tile*>> m_grid;
    int m_width;
    int m_height;
public:
    Map(int width, int height);
    ~Map();
    void placeTile(int x, int y, Tile* tile);
    Tile* getTile(int x, int y);
    int getWidth();
    int getHeight();

};


#endif //ZOO_PROJEKT_MAP_H