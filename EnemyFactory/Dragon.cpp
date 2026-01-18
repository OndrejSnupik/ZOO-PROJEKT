//
// Created by hoang on 16/12/2025.
//

#include "Dragon.h"

Dragon::Dragon() {
    setAttack(25);
    setHeath(190);
}

Dragon::~Dragon() {
    std::cout << "Victory" << std::endl;
    //quit game or display the menu
}

char Dragon::getSymbol() {
    return 'D';
}
