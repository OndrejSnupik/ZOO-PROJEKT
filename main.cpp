//
// Created by ondra on 04/12/2025.
//

#include <iostream>
#include "Tile.h"
#include "Hallway.h"

int main() {
    std::cout << "--- TEST DLAZDICE ---" << std::endl;

    Hallway* startTile = new Hallway(true, true, true, false);

    startTile->printTile(true);

    std::cout << "\n--- PO OTOKCENI ---" << std::endl;
    startTile->rotate();
    startTile->printTile(true);

    delete startTile;

    return 0;
}
