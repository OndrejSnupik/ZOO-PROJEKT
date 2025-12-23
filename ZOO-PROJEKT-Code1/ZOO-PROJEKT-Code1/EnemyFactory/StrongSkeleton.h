//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_STRONGSKELETON_H
#define ZOO_PROJEKT_STRONGSKELETON_H

#include "Skeleton.h"

class StrongSkeleton : public Skeleton{
private:
    int m_attack;
    int m_heath;
public:
    StrongSkeleton();
    int getAttack() override;
    int getHeath() override;
    char getSymbol() override;
};



#endif //ZOO_PROJEKT_STRONGSKELETON_H