//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_WEAKTROLL_H
#define ZOO_PROJEKT_WEAKTROLL_H

#include "Troll.h"

class WeakTroll : public Troll{
private:
    int m_attack;
    int m_heath;
public:
    WeakTroll();
    int getAttack() override;
    int getHeath() override;
    char getSymbol() override;
};


#endif //ZOO_PROJEKT_WEAKTROLL_H