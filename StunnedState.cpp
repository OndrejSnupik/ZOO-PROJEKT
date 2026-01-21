//
// Created by hoang on 21/01/2026.
//

#include "StunnedState.h"

StunnedState::StunnedState() {
    m_duration = 1;
    m_isStunned = true;
}

void StunnedState::printState() {
    std::cout <<"------------------------------\n";
    std::cout << "Jsi omracen!!!" << std::endl;
}

void StunnedState::printEndState() {
    std::cout <<"------------------------------\n";
    std::cout << "Citis se opet normalne."<< std::endl;
}

int StunnedState::getModifyDamage(int damage) {
    return damage;
}

bool StunnedState::getIsStunned() {
    return m_isStunned;
}

void StunnedState::onTurn() {
    if (m_duration > 0) {
        m_duration--;
    }
}

bool StunnedState::isStateEnd() {
    return m_duration == 0;
}
