//
// Created by hoang on 23/12/2025.
//

#include "Enemy.h"



Enemy::Enemy() {
    m_attack = 0;
    m_heath = 0;
    m_debuffChance = 0;
    m_debuff = DebuffType::None;
}

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

void Enemy::setName(std::string name) {
    m_name = name;
}

void Enemy::setDebuff(DebuffType debuff, unsigned int chance) {
    m_debuff = debuff;
    m_debuffChance = chance;
}

DebuffType Enemy::getDebuff() {
    return m_debuff;
}

unsigned int Enemy::getDebuffChance() {
    return m_debuffChance;
}

std::string Enemy::getName() {
    return m_name;
}
