//
// Created by ondra on 10/12/2025.
//

#ifndef ZOO_PROJEKT_HERO_H
#define ZOO_PROJEKT_HERO_H

#include <string>

class Hero {
private:
    std::string m_name;
    int m_x;  //  Souřadnice x hrdiny
    int m_y;  //  Suřadnice y hrdiny
    int m_hp; //  Počet životů
    // int m_level;
    int m_baseAttack;
public:
    Hero(int x, int y, int hp, int baseAttack);
    int getX();
    int getY();
    int getHp();
    void setPosition(int x, int y);
    void changeHp(int hp);
    void setHeath(int amount);
    int getBaseAttack();
    std::string getName();

    // void levelUp();
    // void getItem();
    // void dropItem();
};

#endif //ZOO_PROJEKT_HERO_H