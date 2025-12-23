//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_DRAGON_H
#define ZOO_PROJEKT_DRAGON_H

#include "../Menu.h"
#include<iostream>
#include "Enemy.h"

class Dragon : public Enemy {
private:
    int m_attack;
    int m_heath;
public:
    Dragon();
    ~Dragon() override;
    int getAttack() override;
    int getHeath() override;
    char getSymbol() override;
};


#endif //ZOO_PROJEKT_DRAGON_H