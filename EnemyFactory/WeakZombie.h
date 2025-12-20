//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_WEAKZOMBIE_H
#define ZOO_PROJEKT_WEAKZOMBIE_H

#include "Zombie.h"
class WeakZombie : public Zombie {
private:
    int m_attack;
    int m_heath;
public:
    WeakZombie();
    int getAttack() override;
    int getHeath() override;
};


#endif //ZOO_PROJEKT_WEAKZOMBIE_H