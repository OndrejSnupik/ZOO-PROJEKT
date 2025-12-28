//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_EASYENEMYFACTORY_H
#define ZOO_PROJEKT_EASYENEMYFACTORY_H

#include "EnemyFactory.h"
#include "WeakZombie.h"
#include "WeakSkeleton.h"
#include "WeakTroll.h"

class EasyEnemyFactory : public EnemyFactory {
    Zombie* getZombie() override;
    Skeleton* getSkeleton() override;
    Troll* getTroll() override;
    Dragon* getDragon();
};


#endif //ZOO_PROJEKT_EASYENEMYFACTORY_H