//
// Created by hoang on 16/12/2025.
//

#include "Dragon.h"

Dragon::Dragon() {
    m_attack = 25;
    m_heath = 200;
}

Dragon::~Dragon() {
    std::cout << "Victory" << std::endl;
    //quit game or display the menu
}

int Dragon::getAttack() {
    return m_attack;
}

int Dragon::getHeath() {
    return m_heath;;
}
