//
// Created by ondra on 10/12/2025.
//

#ifndef ZOO_PROJEKT_HERO_H
#define ZOO_PROJEKT_HERO_H


class Hero {
private:
    int m_x;  //  Souřadnice x hrdiny
    int m_y;  //  Suřadnice y hrdiny
    int m_hp; //  Počet životů
public:
    Hero(int x, int y, int hp);
    int getX();
    int getY();
    int getHp();
    void setPosition(int x, int y);
    void changeHp(int hp);
};


#endif //ZOO_PROJEKT_HERO_H