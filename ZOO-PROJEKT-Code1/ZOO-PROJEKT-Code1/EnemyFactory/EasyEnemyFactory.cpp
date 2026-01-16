//
// Created by hoang on 16/12/2025.
//

#include "EasyEnemyFactory.h"

Zombie * EasyEnemyFactory::getZombie() {
    return new WeakZombie();
}

Skeleton * EasyEnemyFactory::getSkeleton() {
    return new WeakSkeleton();
}

Troll * EasyEnemyFactory::getTroll() {
    return new WeakTroll();
}

Dragon * EasyEnemyFactory::getDragon() {
    return new Dragon();
}
