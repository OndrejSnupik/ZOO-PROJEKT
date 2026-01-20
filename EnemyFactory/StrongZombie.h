//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_STRONGZOMBIE_H
#define ZOO_PROJEKT_STRONGZOMBIE_H


#include "Zombie.h"

class StrongZombie : public Zombie {
public:
    StrongZombie();
    char getSymbol() override;
};

#endif //ZOO_PROJEKT_STRONGZOMBIE_H