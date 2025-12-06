//
// Created by ondra on 06/12/2025.
//

#ifndef ZOO_PROJEKT_TILE_H
#define ZOO_PROJEKT_TILE_H
#include <string>


class Tile {
protected:
    bool m_exits[4];
    std::string m_type;
public:
    Tile(std::string type);
    virtual ~Tile() = default;
    bool hasExit(int direction);
    std::string getType();
    void rotate();
    virtual void printTile(bool hasHero);
};


#endif //ZOO_PROJEKT_TILE_H