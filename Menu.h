//
// Created by ondra on 14/12/2025.
//

#ifndef ZOO_PROJEKT_MENU_H
#define ZOO_PROJEKT_MENU_H


class Menu {
private:
    bool m_isRunning; // Určuje jestli menu jede
    void printOptions();
    int chooseDifficulty();
    void startNewGame();
    void showCredits();

public:
    Menu();
    void run();
};


#endif //ZOO_PROJEKT_MENU_H