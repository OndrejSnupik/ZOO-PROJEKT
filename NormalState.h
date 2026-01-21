//
// Created by hoang on 21/01/2026.
//

#ifndef ZOO_PROJEKT_NORMALSTATE_H
#define ZOO_PROJEKT_NORMALSTATE_H

#include "HeroState.h"

class NormalState : public HeroState{
public:
    NormalState() = default;
    void printState() override;
    void printEndState() override;
    int getModifyDamage(int damage) override;
    bool getIsStunned() override;
    void onTurn() override;
    bool isStateEnd() override;
};

#endif //ZOO_PROJEKT_NORMALSTATE_H