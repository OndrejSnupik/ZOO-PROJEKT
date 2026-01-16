//
// Created by ondra on 10/12/2025.
//

#include "Hero.h"

#include <iostream>

// Inicializuje hrdinu s danou polohou a životy
Hero::Hero(int x, int y, int hp) {
    m_x = x;
    m_y = y;
    m_hp = hp;
}

int Hero::getX() {
    return m_x;
}

int Hero::getY() {
    return m_y;
}

int Hero::getHp() {
    return m_hp;
}

void Hero::setPosition(int x, int y) {
    m_x = x;
    m_y = y;
}

void Hero::changeHp(int hp) {
    m_hp += hp;

    if (m_hp < 0) {
        m_hp = 0;
        std::cout << "Hrdina zemrel" << std::endl;
    }
}





