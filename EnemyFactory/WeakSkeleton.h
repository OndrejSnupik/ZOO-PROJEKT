//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_WEAKSKELETON_H
#define ZOO_PROJEKT_WEAKSKELETON_H

#include "Skeleton.h"

class WeakSkeleton : public Skeleton{
public:
    WeakSkeleton();
    char getSymbol() override;
};


#endif //ZOO_PROJEKT_WEAKSKELETON_H