//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_WEAKSKELETON_H
#define ZOO_PROJEKT_WEAKSKELETON_H

#include "Skeleton.h"

class WeakSkeleton : public Skeleton{
private:
    int m_attack;
    int m_heath;
public:
    WeakSkeleton();
    int getAttack() override;
    int getHeath() override;
};


#endif //ZOO_PROJEKT_WEAKSKELETON_H