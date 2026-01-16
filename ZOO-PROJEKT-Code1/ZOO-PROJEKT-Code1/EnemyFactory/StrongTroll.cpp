//
// Created by hoang on 16/12/2025.
//

#include "StrongTroll.h"

StrongTroll::StrongTroll() {
    m_attack = 20;
    m_heath = 120;
}

int StrongTroll::getAttack() {
    return m_attack;
}

int StrongTroll::getHeath() {
    return m_heath;
}

char StrongTroll::getSymbol() {
    return 'T';
}
