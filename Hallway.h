//
// Created by ondra on 06/12/2025.
//

#ifndef ZOO_PROJEKT_HALLWAY_H
#define ZOO_PROJEKT_HALLWAY_H
#include "Tile.h"

class Hallway: public Tile {
public:
    Hallway(bool up, bool down, bool left, bool right);
};

#endif //ZOO_PROJEKT_HALLWAY_H