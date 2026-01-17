//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_WEAKZOMBIE_H
#define ZOO_PROJEKT_WEAKZOMBIE_H

#include "Zombie.h"

class WeakZombie : public Zombie {
public:
    WeakZombie();
    char getSymbol() override;
};


#endif //ZOO_PROJEKT_WEAKZOMBIE_H