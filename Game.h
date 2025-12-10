//
// Created by ondra on 10/12/2025.
//

#ifndef ZOO_PROJEKT_GAME_H
#define ZOO_PROJEKT_GAME_H
#include "Hero.h"
#include "Map.h"


class Game {
    Map* m_map;
    Hero* m_hero;
    bool m_isRunning;

    void handleInput();
    void generateRandomTile(int x, int y);
public:
    Game();
    ~Game();
    void run();
};


#endif //ZOO_PROJEKT_GAME_H