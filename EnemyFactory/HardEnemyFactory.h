//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_HARDENEMYFACTORY_H
#define ZOO_PROJEKT_HARDENEMYFACTORY_H

#include "EnemyFactory.h"
#include "StrongZombie.h"
#include "StrongSkeleton.h"
#include "StrongTroll.h"

class HardEnemyFactory : public EnemyFactory {
    public:
    HardEnemyFactory()= default;
    Zombie* getZombie() override;
    Skeleton* getSkeleton() override;
    Troll* getTroll() override;
    Dragon* getDragon();
};


#endif //ZOO_PROJEKT_HARDENEMYFACTORY_H