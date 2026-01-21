//
// Created by ondra on 10/12/2025.
//

#ifndef ZOO_PROJEKT_HERO_H
#define ZOO_PROJEKT_HERO_H

#include <iostream>
#include "HeroState.h"
#include "NormalState.h"
#include "StunnedState.h"
#include "WeakenState.h"

class Hero {
private:
    std::string m_name;
    int m_x;  //  Souřadnice x hrdiny
    int m_y;  //  Suřadnice y hrdiny
    int m_hp; //  Počet životů
    // int m_level;
    int m_baseAttack;
    HeroState * m_state;
public:
    Hero(int x, int y, int hp, int baseAttack);
    ~Hero();
    std::string getName();
    int getX();
    int getY();
    int getHp();
    void setPosition(int x, int y);
    void changeHp(int hp);
    void setHp(int amount);
    int getAttack();
    void setState(HeroState * newState );
    void updateState();
    bool isStunned();
};

#endif //ZOO_PROJEKT_HERO_H