//
// Created by hoang on 16/12/2025.
//

#include "WeakTroll.h"

#include <set>

WeakTroll::WeakTroll() {
    setAttack(8);
    setHeath(80);
    setDebuff(DebuffType::Stun, 10);
    setName("Troll");
}

char WeakTroll::getSymbol() {
    return 'T';
}
