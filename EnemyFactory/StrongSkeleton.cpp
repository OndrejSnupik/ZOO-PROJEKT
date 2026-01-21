//
// Created by hoang on 16/12/2025.
//

#include "StrongSkeleton.h"

StrongSkeleton::StrongSkeleton() {
    setAttack(15);
    setHeath(70);
    setDebuff(DebuffType::Weaken, 10);
    setName("Strong Skeleton");
}

char StrongSkeleton::getSymbol() {
    return 'S';
}
