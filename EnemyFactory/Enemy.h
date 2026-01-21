//
// Created by hoang on 23/12/2025.
//

#ifndef ZOO_PROJEKT_ENEMY_H
#define ZOO_PROJEKT_ENEMY_H

#include <string>

enum class DebuffType {
    None,
    Weaken,
    Stun
};

class Enemy {
private:
    int m_attack;
    int m_heath;
    std::string m_name;
    DebuffType m_debuff;
    unsigned int m_debuffChance;
public:
    Enemy();
    virtual ~Enemy() = default;
    int getAttack();
    int getHeath();
    void setHeath(int amount);
    void setAttack(int amount);
    void setName(std::string name);
    virtual char getSymbol() = 0;
    void setDebuff(DebuffType debuff, unsigned int chance);
    DebuffType getDebuff();
    unsigned int getDebuffChance();
    std::string getName();
};


#endif //ZOO_PROJEKT_ENEMY_H