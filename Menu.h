// Game.h
#ifndef ZOO_PROJEKT_GAME_H
#define ZOO_PROJEKT_GAME_H

#include "Map.h"

class Menu {
private:
    Map* m_map;
    bool m_isRunning;

    void printMenu();
    void runGameLoop(); // Tady bude logika hry (chození po mapě atd.)

public:
    Menu();
    ~Menu();
    void run(); // Hlavní spouštěcí metoda
};

#endif //ZOO_PROJEKT_GAME_H