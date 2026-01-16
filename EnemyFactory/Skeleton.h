//
// Created by hoang on 16/12/2025.
//

#ifndef ZOO_PROJEKT_SKELETON_H
#define ZOO_PROJEKT_SKELETON_H


class Skeleton {
public:
    Skeleton();
    virtual ~Skeleton();
    virtual int getAttack() = 0;
    virtual int getHeath() = 0;
};


#endif //ZOO_PROJEKT_SKELETON_H