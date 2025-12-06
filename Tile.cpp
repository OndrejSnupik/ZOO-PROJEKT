//
// Created by ondra on 06/12/2025.
//
#include "Tile.h"

#include <iostream>

Tile::Tile(std::string type) {
    m_type = type;
    for (int i=0; i<4; i++) {
        m_exits[i] = false;
    }
}
bool Tile::hasExit(int direction) {
    if (direction >= 0 && direction < 4) {
        return m_exits[direction];
    }
    return false;
}
std::string Tile::getType() {
    return m_type;
}
void Tile::rotate() {
    bool oldUp = m_exits[0];
    bool oldDown = m_exits[1];
    bool oldLeft = m_exits[2];
    bool oldRight = m_exits[3];

    m_exits[3] = oldUp;
    m_exits[1] = oldRight;
    m_exits[2] = oldDown;
    m_exits[0] = oldLeft;
}

void Tile::printTile(bool hasHero) {
    const int SIZE = 7;
    char point [SIZE][SIZE];

    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            point[x][y] = '#';
        }
    }
    for (int x = 1; x < SIZE - 1; x++) {
        for (int y = 1; y < SIZE -1; y++) {
            point[x][y] = ' ';
        }
    }

    int center = SIZE / 2;

    if (m_exits[0]) {
        point[0][center] = ' ';
        point[0][center-1] = ' ';
        point[0][center+1] = ' ';
    }
    if (m_exits[1]) {
        point[SIZE-1][center] = ' ';
        point[SIZE-1][center-1] = ' ';
        point[SIZE-1][center+1] = ' ';
    }
    if (m_exits[2]) {
        point[center][0] = ' ';
        point[center-1][0] = ' ';
        point[center+1][0] = ' ';
    }
    if (m_exits[3]) {
        point[center][SIZE-1] = ' ';
        point[center-1][SIZE-1] = ' ';
        point[center+1][SIZE-1] = ' ';
    }
    if (hasHero) {
        point[center][center] = 'H';
    }
    for (int x = 0; x < SIZE; x++) {
        std::cout << "\t";
        for (int y = 0; y < SIZE; y++) {
            std::cout << point[x][y] << " ";
        }
        std::cout << std::endl;
    }
}



