//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_STRONGZOMBIE_H
#define ZOO_PROJEKT_STRONGZOMBIE_H


#include "Zombie.h"

class StrongZombie : public Zombie {
private:
    int m_attack;
    int m_heath;
public:
    StrongZombie();
    int getAttack() override;
    int getHeath() override;
    char getSymbol() override;
};


#endif //ZOO_PROJEKT_STRONGZOMBIE_H