//
// Created by hoang on 16/12/2025.
//

#include "WeakZombie.h"

WeakZombie::WeakZombie() {
    setAttack(5);
    setHeath(70);
    setDebuff(DebuffType::Weaken, 10);
    setName("Zombie");
}

char WeakZombie::getSymbol() {
    return 'Z';
}
