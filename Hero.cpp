//
// Created by ondra on 10/12/2025.
//

#include "Hero.h"

#include <iostream>

// Inicializuje hrdinu s danou polohou a životy
Hero::Hero(int x, int y, int hp, int baseAttack) {
    m_x = x;
    m_y = y;
    m_hp = hp;
    m_baseAttack = baseAttack;
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
}

void Hero::setHp(int amount) {
    m_hp = amount;
}

int Hero::getBaseAttack() {
    return m_baseAttack;
}

std::string Hero::getName() {
    return m_name;
}





