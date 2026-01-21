//
// Created by hoang on 21/01/2026.
//

#ifndef ZOO_PROJEKT_HEROSTATE_H
#define ZOO_PROJEKT_HEROSTATE_H

#include <iostream>
class Hero;// forward declaration

class HeroState {
public:
    HeroState() = default;
    virtual ~HeroState() = default;
    virtual void printState() = 0;
    virtual void printEndState() = 0;
    virtual int getModifyDamage(int damage) = 0;
    virtual bool getIsStunned() = 0;
    virtual void onTurn() = 0;
    virtual bool isStateEnd() = 0;
};

#endif //ZOO_PROJEKT_HEROSTATE_H
