//
// Created by hoang on 23/12/2025.
//

#ifndef ZOO_PROJEKT_ENEMY_H
#define ZOO_PROJEKT_ENEMY_H


class Enemy {
public:
    Enemy() = default;
    virtual ~Enemy() = default;
    virtual int getAttack() = 0;
    virtual int getHeath() = 0;
    virtual char getSymbol() = 0;
};


#endif //ZOO_PROJEKT_ENEMY_H