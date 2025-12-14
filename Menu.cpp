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
    std::cout << " /$$   /$$                              /$$      \n";
    std::cout << "| $$  /$$/                             | $$      \n";
    std::cout << "| $$ /$$/   /$$$$$$   /$$$$$$  /$$$$$$ | $$   /$$\n";
    std::cout << "| $$$$$/   |____  $$ /$$__  $$|____  $$| $$  /$$/\n";
    std::cout << "| $$  $$    /$$$$$$$| $$  \\__/ /$$$$$$$| $$$$$$/ \n";
    std::cout << "| $$\\  $$  /$$__  $$| $$      /$$__  $$| $$_  $$ \n";
    std::cout << "| $$ \\  $$|  $$$$$$$| $$     |  $$$$$$$| $$ \\  $$\n";
    std::cout << "|__/  \\__/ \\_______/|__/      \\_______/|__/  \\__/" << std::endl;
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

        // Ošetření vstupu (kdyby zadal písmeno)
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
    // Tady vytvoříme celou tu hru, kterou jsme doteď ladili
    Game* myGame = new Game();

    // Spustíme ji (program se tady "zasekne" dokud hra neskončí)
    myGame->run();

    // Jakmile hráč dá ve hře 'q', metoda run() skončí a program pokračuje zde:
    delete myGame; // Uklidíme po hře

    std::cout << "Hra byla ukoncena. Vracim se do menu..." << std::endl;
}

void Menu::showCredits() {
    std::cout << "\n--- O AUTORECH ---" << "\n";
    std::cout << "- Šňupík Ondřej" << "\n";
    std::cout << "- Bunža Petr" << "\n";
    std::cout << "- Nguyen The Hoang" << "\n";
    std::cout << "- Verze: 1.0 (Karak)" << "\n";
    std::cout << "...Zmackni Enter pro navrat..." << std::endl;

    // Pauza na přečtení
    std::cin.ignore();
    std::cin.get();
}