//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_ZOMBIE_H
#define ZOO_PROJEKT_ZOMBIE_H


class Zombie {
public:
    Zombie();
    virtual ~Zombie();
    virtual int getAttack() = 0;
    virtual int getHeath() = 0;
};


#endif //ZOO_PROJEKT_ZOMBIE_H