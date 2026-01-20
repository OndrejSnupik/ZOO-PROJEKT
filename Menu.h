//
// Created by ondra on 14/12/2025.
//

#ifndef ZOO_PROJEKT_MENU_H
#define ZOO_PROJEKT_MENU_H

#include <iostream>
#include <limits> // Pro cin.ignore

enum class MenuAction {
    startNewGame,
    showCredits,
    quit
};

class Menu {
private:
    void printOptions();
public:
    Menu() = default;
    MenuAction run();
    int chooseDifficulty();
    void showCredits();
};


#endif //ZOO_PROJEKT_MENU_H