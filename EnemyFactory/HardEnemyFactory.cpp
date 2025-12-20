//
// Created by hoang on 16/12/2025.
//

#include "HardEnemyFactory.h"

Zombie * HardEnemyFactory::getZombie() {
    return new StrongZombie();
}

Skeleton * HardEnemyFactory::getSkeleton() {
    return new StrongSkeleton();
}

Troll * HardEnemyFactory::getTroll() {
    return new StrongTroll();
}

Dragon * HardEnemyFactory::getDragon() {
    return new Dragon();
}
