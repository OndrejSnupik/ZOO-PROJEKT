//
// Created by hoang on 16/12/2025.
//

#include "StrongZombie.h"

StrongZombie::StrongZombie() {
    m_attack = 10;
    m_heath = 100;
}

int StrongZombie::getAttack() {
    return m_attack;
}

int StrongZombie::getHeath() {
    return m_heath;
}
