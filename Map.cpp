//
// Created by ondra on 06/12/2025.
//

#include "Map.h"

#include <iostream>

Map::Map(int width, int height) {
    m_width = width;
    m_height = height;

    for (int y = 0; y < m_height; y++) {
        std::vector<Tile*> row;
        for (int x = 0; x < m_width; x++) {
            row.push_back(nullptr);
        }
        m_grid.push_back(row);
    }
}
Map::~Map() {
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            if (m_grid[y][x] != nullptr) {
                delete m_grid[y][x];
                m_grid[y][x] = nullptr;
            }
        }
    }
}
void Map::placeTile(int x, int y, Tile *tile) {
    if (x < 0 || x >= m_width || y < 0 || y >= m_height) {
        std::cerr << "Pokus o vlozeni Tile mimo mapu" << std::endl;
        delete tile;
        return;
    }

    if (m_grid[y][x] != nullptr) {
        delete m_grid[y][x];
    }

    m_grid[y][x] = tile;
}
Tile* Map::getTile(int x, int y) {
    if (x >= 0 && x < m_width && y>= 0 && y < m_height) {
        return m_grid[y][x];
    }else {
        return nullptr;
    }


}


