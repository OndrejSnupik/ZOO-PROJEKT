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
    DragonDied,
    None
};

class CombatSystem {
private:
    Hero* m_hero;
    Enemy* m_enemy;
    CombatResult m_result;
public:
    CombatSystem(Hero * hero, Enemy * enemy);
    void run();
    CombatResult getCombatResult();
private:
    void draw();
    void drawCombatUI();

    void handleCombat();
    void handleFlee();

    void heroTurn();
    void enemyAttack();
    void normalAttack();

};


#endif //ZOO_PROJEKT_COMBATSYSTEM_H