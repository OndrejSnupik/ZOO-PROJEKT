//
// Created by hoang on 16/12/2025.
//

#include "WeakTroll.h"

WeakTroll::WeakTroll() {
    m_attack = 10;
    m_heath = 70;
}

int WeakTroll::getAttack() {
    return m_attack;
}

int WeakTroll::getHeath() {
    return m_heath;
}
