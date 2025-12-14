//
// Created by ondra on 14/12/2025.
//

#include "Menu.h"
#include "Game.h" // DŮLEŽITÉ: Menu musí znát Hru
#include <iostream>
#include <limits> // Pro cin.ignore

Menu::Menu() {
    m_isRunning = true;
}

void Menu::printOptions() {
    std::cout << "\n=========================" << std::endl;
    std::cout << "      ZOO PROJEKT        " << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "1. Nova hra" << std::endl;
    std::cout << "2. O autorech" << std::endl;
    std::cout << "0. Konec" << std::endl;
    std::cout << "=========================" << std::endl;
}

void Menu::run() {
    while (m_isRunning) {
        printOptions();

        int choice;
        std::cout << "Tva volba: ";

        // Zkontroluje jestli byl zadán správný typ vstupu (číslo)
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Neplatny vstup!" << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                startNewGame(); // Tady se přepneme do hry
                break;
            case 2:
                showCredits();
                break;
            case 0:
                m_isRunning = false;
                std::cout << "Nashledanou!" << std::endl;
                break;
            default:
                std::cout << "Neplatna volba." << std::endl;
                break;
        }
    }
}

void Menu::startNewGame() {
    // Vytvoří novou instanci hry
    Game* myGame = new Game();

    // Předá řízení herni třídě a program čeká dokud hra neskončí
    myGame->run();

    delete myGame; // Po skončení hry smažeme instanci hry

    std::cout << "Hra byla ukoncena. Vracim se do menu..." << std::endl;
}

void Menu::showCredits() {
    std::cout << "\n--- O AUTORECH ---" << std::endl;
    std::cout << "Vyvoril: Ondra a jeho AI partak Gemini" << std::endl;
    std::cout << "Verze: 1.0 (Dungeon Crawler)" << std::endl;
    std::cout << "Zmackni Enter pro navrat..." << std::endl;

    // Počká na stisk klávesy enter
    std::cin.ignore();
    std::cin.get();
}