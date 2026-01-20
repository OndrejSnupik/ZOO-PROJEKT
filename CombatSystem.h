//
// Created by hoang on 24/12/2025.
//

#ifndef ZOO_PROJEKT_COMBATSYSTEM_H
#define ZOO_PROJEKT_COMBATSYSTEM_H

#include <iostream>
#include <random>
#include <limits>
#include "EnemyFactory/Enemy.h"
#include "Hero.h"

enum class CombatResult {
    EnemyDied,
    HeroDied,
    HeroRan,
    DragonDied
};

class CombatSystem {
private:
    Hero* m_hero;
    Enemy* m_enemy;
public:
    CombatSystem(Hero * hero, Enemy * enemy);

    CombatResult run();
private:
    void draw();
    void drawCombatUI();

    CombatResult handleCombat();
    CombatResult handleRun();

    void useBasicAttack();

};


#endif //ZOO_PROJEKT_COMBATSYSTEM_H