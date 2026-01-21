//
// Created by hoang on 21/01/2026.
//

#ifndef ZOO_PROJEKT_WEAKENSTATE_H
#define ZOO_PROJEKT_WEAKENSTATE_H

#include "HeroState.h"

class WeakenState : public HeroState{
private:
    unsigned int m_duration;
public:
    WeakenState();
    void printState() override;
    void printEndState() override;
    int getModifyDamage(int damage) override;
    bool getIsStunned() override;
    void onTurn() override;
    bool isStateEnd() override;
};

#endif //ZOO_PROJEKT_WEAKENSTATE_H