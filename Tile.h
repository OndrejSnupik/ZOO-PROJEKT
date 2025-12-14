//
// Created by ondra on 06/12/2025.
//

#ifndef ZOO_PROJEKT_TILE_H
#define ZOO_PROJEKT_TILE_H
#include <string>


class Tile {
protected:
    bool m_exits[4]; // Pole určující, kde jsou východy (0=sever, 1=jih atd.)
    std::string m_type;
public:
    Tile(std::string type);
    virtual ~Tile() = default;

    bool hasExit(int direction);
    std::string getType();
    void rotate();// Otočí orientaci dlaždice
    virtual void printTile(bool hasHero);
};


#endif //ZOO_PROJEKT_TILE_H