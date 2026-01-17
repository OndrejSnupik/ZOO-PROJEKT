//
// Created by hoang on 23/12/2025.
//

#include "Enemy.h"

int Enemy::getAttack() {
    return m_attack;
}

int Enemy::getHeath() {
    return m_heath;
}

void Enemy::setHeath(int amount) {
    m_heath = amount;
}

void Enemy::setAttack(int amount) {
    m_attack = amount;
}
