//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_WEAKTROLL_H
#define ZOO_PROJEKT_WEAKTROLL_H

#include "Troll.h"

class WeakTroll : public Troll{
public:
    WeakTroll();
    char getSymbol() override;
};

#endif //ZOO_PROJEKT_WEAKTROLL_H