//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_ENEMYFACTORY_H
#define ZOO_PROJEKT_ENEMYFACTORY_H

#include "Zombie.h"
#include "Skeleton.h"
#include "Troll.h"
#include "Dragon.h"

class EnemyFactory {
    public:
    EnemyFactory() = default;
    virtual ~EnemyFactory() = default;
    virtual Zombie* getZombie() = 0;
    virtual Skeleton* getSkeleton() = 0;
    virtual Troll* getTroll() = 0;
    virtual Dragon* getDragon() = 0;
};

#endif //ZOO_PROJEKT_ENEMYFACTORY_H