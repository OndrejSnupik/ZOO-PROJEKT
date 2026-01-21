//
// Created by hoang on 16/12/2025.
//

#include "Dragon.h"

Dragon::Dragon() {
    setAttack(25);
    setHeath(190);
    setDebuff(DebuffType::Stun, 15);
    setName("Fire Dragon");
}

char Dragon::getSymbol() {
    return 'D';
}
