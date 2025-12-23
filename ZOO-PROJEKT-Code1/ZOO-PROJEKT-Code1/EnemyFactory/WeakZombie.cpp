//
// Created by hoang on 16/12/2025.
//

#include "WeakZombie.h"

WeakZombie::WeakZombie() {
    m_attack = 5;
    m_heath = 70;
}

int WeakZombie::getAttack() {
    return m_attack;
}

int WeakZombie::getHeath() {
    return m_heath;
}

char WeakZombie::getSymbol() {
    return 'Z';
}
