//
// Created by ondra on 06/12/2025.
//
#include "Tile.h"

#include <iostream>

Tile::Tile(std::string type) {
    m_enemy = nullptr;
    m_type = type;
    // Na začátku nastaví všechny cesty jako zavřené
    for (int i=0; i<4; i++) {
        m_exits[i] = false;
    }
}

Tile::~Tile() {
        delete m_enemy;
}

bool Tile::hasExit(int direction) {
    // Ověří platnost směru a vrátí jestli tam vede cesta
    if (direction >= 0 && direction < 4) {
        return m_exits[direction];
    }
    return false;
}
std::string Tile::getType() {
    return m_type;
}
void Tile::rotate() {
    // Uloží si aktuální hodnoty před změnou
    bool oldUp = m_exits[0];
    bool oldDown = m_exits[1];
    bool oldLeft = m_exits[2];
    bool oldRight = m_exits[3];

    // Přehodí hodnoty po směru hodinových ručiček
    m_exits[3] = oldUp;
    m_exits[1] = oldRight;
    m_exits[2] = oldDown;
    m_exits[0] = oldLeft;
}

void Tile::printTile(bool hasHero) {
    const int SIZE = 7;
    char point [SIZE][SIZE];

    // Nejprve vyplní celou plochu zdí
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            point[y][x] = '#';
        }
    }
    // Vymaže vnitřní prostor (vytvoří podlahu)
    for (int y = 1; y < SIZE - 1; y++) {
        for (int x = 1; x < SIZE -1; x++) {
            point[y][x] = ' ';
        }
    }

    int center = SIZE / 2;

    // Udělá díry do zdí podle toho, kde jsou východy
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

    // Pokud je na dlaždici hrdina, vykreslí ho uprostřed
    if (hasHero) {
        point[center][center] = 'H';
    }
    if (m_enemy!= nullptr) {
        point[center+2][center] = m_enemy->getSymbol();
    }

    // Vypíše výslednou matici znaků do konzole
    for (int y = 0; y < SIZE; y++) {
        std::cout << "\t";
        for (int x = 0; x < SIZE; x++) {
            std::cout << point[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

void Tile::setEnemy(Enemy *enemy) {
    m_enemy = enemy;
}

Enemy * Tile::getEnemy() {
        return m_enemy;
}



