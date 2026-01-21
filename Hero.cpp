//
// Created by ondra on 10/12/2025.
//

#include "Hero.h"



// Inicializuje hrdinu s danou polohou a životy
Hero::Hero(int x, int y, int hp, int baseAttack) {
    m_name = "Howard Walters";
    m_x = x;
    m_y = y;
    m_hp = hp;
    m_baseAttack = baseAttack;
    m_state = new NormalState();
}

Hero::~Hero() {
    delete m_state;
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

int Hero::getAttack() {
    return m_state->getModifyDamage(m_baseAttack);
}

std::string Hero::getName() {
    return m_name;
}

void Hero::setState(HeroState * newState) {
    m_state->printEndState();
    delete m_state;
    m_state = newState;
    m_state->printState();
}

void Hero::updateState() {
    m_state->onTurn();
    if (m_state->isStateEnd()) {
        setState(new NormalState());
    }
}

bool Hero::isStunned() {
    return m_state->getIsStunned();
}





