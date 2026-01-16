//
// Created by ondra on 06/12/2025.
//
#include "Hallway.h"

// Konstruktor předává informace o stěnách rodičovské třídě Tile
Hallway::Hallway(bool up, bool down, bool left, bool right) : Tile("Chodba") {
    m_exits[0] = up;
    m_exits[1] = down;
    m_exits[2] = left;
    m_exits[3] = right;
}
