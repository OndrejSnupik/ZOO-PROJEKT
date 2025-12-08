//
// Created by ondra on 04/12/2025.
//

#include <iostream>
#include "Map.h"
#include "Hallway.h"

int main() {
    std::cout << "--- TEST MAPY ---" << std::endl;

    // 1. Vytvoříme mapu 5x5
    Map* myMap = new Map(5, 5);

    // 2. Vložíme chodbu na střed (2,2)
    // Parametry: Up=true, Down=true, Left=true, Right=false
    myMap->placeTile(2, 2, new Hallway(true, true, true, false));

    // 3. Zkusíme ji získat zpět
    Tile* t = myMap->getTile(2, 2);
    if (t != nullptr) {
        std::cout << "Nasel jsem dlazdici na 2,2!" << std::endl;
        t->printTile(true); // Vykreslíme i s hrdinou

        std::cout << "\nTed ji otocime v ramci mapy..." << std::endl;
        t->rotate();
        t->printTile(true);
    }

    // 4. Smazání mapy (měl by se vypsat text o mazání)
    delete myMap;

    return 0;
}
