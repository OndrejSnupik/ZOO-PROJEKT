//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_DRAGON_H
#define ZOO_PROJEKT_DRAGON_H

#include "../Menu.h"
#include<iostream>

class Dragon {
private:
    int m_attack;
    int m_heath;
public:
    Dragon();
    ~Dragon();
    int getAttack();
    int getHeath();
};


#endif //ZOO_PROJEKT_DRAGON_H