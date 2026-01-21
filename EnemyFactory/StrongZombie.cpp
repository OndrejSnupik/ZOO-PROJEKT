//
// Created by hoang on 16/12/2025.
//

#include "StrongZombie.h"

StrongZombie::StrongZombie() {
    setAttack(10);
    setHeath(100);
    setDebuff(DebuffType::Weaken, 15);
    setName("Deadly Zombie");
}

char StrongZombie::getSymbol() {
    return 'Z';
}
