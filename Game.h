//
// Created by ondra on 10/12/2025.
//

#ifndef ZOO_PROJEKT_GAME_H
#define ZOO_PROJEKT_GAME_H
#include "Hero.h"
#include "Map.h"
#include <conio.h> // for _kbhit() and _getch()
#include <windows.h> // for Sleep()


class Game {
    private:
    Map* m_map;
    Hero* m_hero;
    bool m_isRunning; // Indikuje jestli herní smyčka běží

    bool handleInput(); // vstupy z klávesnice
    void generateRandomTile(int x, int y, int incomingDirection); // Generuje novou místnost
public:
    Game();
    ~Game();
    void run(); // Spouští hlavní cyklus hry
};


#endif //ZOO_PROJEKT_GAME_H