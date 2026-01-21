//
// Created by hoang on 16/12/2025.
//

#include "StrongTroll.h"

StrongTroll::StrongTroll() {
    setAttack(14);
    setHeath(120);
    setDebuff(DebuffType::Stun, 15);
    setName("Ice Troll");
}

char StrongTroll::getSymbol() {
    return 'T';
}
