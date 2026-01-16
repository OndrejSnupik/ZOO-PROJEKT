//
// Created by hoang on 16/12/2025.
//

#include "StrongSkeleton.h"

StrongSkeleton::StrongSkeleton() {
    m_attack = 20;
    m_heath = 70;
}

int StrongSkeleton::getAttack() {
    return m_attack;
}

int StrongSkeleton::getHeath() {
    return m_heath;
}

char StrongSkeleton::getSymbol() {
    return 'S';
}
