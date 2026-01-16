//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_STRONGTROLL_H
#define ZOO_PROJEKT_STRONGTROLL_H

#include "Troll.h"

class StrongTroll : public Troll{
private:
    int m_attack;
    int m_heath;
public:
    StrongTroll();
    int getAttack() override;
    int getHeath() override;
    char getSymbol() override;
};


#endif //ZOO_PROJEKT_STRONGTROLL_H