//
// Created by ondra on 06/12/2025.
//

#ifndef ZOO_PROJEKT_MAP_H
#define ZOO_PROJEKT_MAP_H
#include <vector>

#include "Tile.h"


class Map {
private:
    // Mřížka mapy uložená jako 2D pole do Vektoru
    std::vector<std::vector<Tile*>> m_grid;
    int m_width;
    int m_height;
public:
    Map(int width, int height);
    ~Map();
    void placeTile(int x, int y, Tile* tile); // Vloží dlaždici na konkrétní místo
    Tile* getTile(int x, int y);              // Vrátí ukazatel na dlaždici na dané pozici
    int getWidth();
    int getHeight();

};


#endif //ZOO_PROJEKT_MAP_H