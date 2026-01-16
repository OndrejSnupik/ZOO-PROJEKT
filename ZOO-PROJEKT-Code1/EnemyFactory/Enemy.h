//
// Created by hoang on 23/12/2025.
//

#ifndef ZOO_PROJEKT_ENEMY_H
#define ZOO_PROJEKT_ENEMY_H


class Enemy {
private:
    int m_attack = 0;
    int m_heath = 0;
public:
    Enemy() = default;
    virtual ~Enemy() = default;
    int getAttack();
    int getHeath();
    void setHeath(int amount);
    void setAttack(int amount);
    virtual char getSymbol() = 0;
};


#endif //ZOO_PROJEKT_ENEMY_H