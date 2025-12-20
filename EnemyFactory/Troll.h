//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_TROLL_H
#define ZOO_PROJEKT_TROLL_H


class Troll {
public:
    Troll();
    virtual ~Troll();
    virtual int getAttack() = 0;
    virtual int getHeath() = 0;
};


#endif //ZOO_PROJEKT_TROLL_H