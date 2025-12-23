//
// Created by hoang on 16/12/2025.
//

#include "WeakSkeleton.h"

WeakSkeleton::WeakSkeleton() {
    m_attack = 10;
    m_heath = 50;
}

int WeakSkeleton::getAttack() {
    return m_attack;
}

int WeakSkeleton::getHeath() {
    return m_heath;
}

char WeakSkeleton::getSymbol() {
    return 'S';
}
