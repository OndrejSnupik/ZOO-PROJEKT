//
// Created by hoang on 21/01/2026.
//

#include "WeakenState.h"

WeakenState::WeakenState() {
    m_duration = 2;
}

void WeakenState::printState() {
    std::cout <<"------------------------------\n";
    std::cout << "Citis se oslabeny... "<< std::endl;
}

void WeakenState::printEndState() {
    std::cout <<"------------------------------\n";
    std::cout << "Citis se opet normalne."<< std::endl;
}

int WeakenState::getModifyDamage(int damage) {
    return damage/2;
}

bool WeakenState::getIsStunned() {
    return false;
}

void WeakenState::onTurn() {
    if (m_duration > 0) {
        m_duration--;
    }
}

bool WeakenState::isStateEnd() {
    return m_duration == 0;
}
