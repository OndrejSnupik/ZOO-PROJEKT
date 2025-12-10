// Game.cpp
#include "Menu.h"
#include "Hallway.h"
#include <iostream>
#include <limits> // Pro cin.ignore

Menu::Menu() {
    m_map = nullptr;
    m_isRunning = true;
}

Menu::~Menu() {
    if (m_map != nullptr) {
        delete m_map;
    }
}

void Menu::run() {
    while (m_isRunning) {
        printMenu();

        int choice;
        std::cout << "Tva volba: ";
        if (!(std::cin >> choice)) {
            // Ošetření chyby, pokud uživatel zadá písmeno místo čísla
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Neplatny vstup, zkus to znovu." << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                runGameLoop();
                break;
            case 2:
                std::cout << "Tady by byly informace o autorech..." << std::endl;
                break;
            case 0:
                m_isRunning = false;
                std::cout << "Ukoncuji hru..." << std::endl;
                break;
            default:
                std::cout << "Neplatna volba." << std::endl;
                break;
        }
    }
}

void Menu::printMenu() {
    std::cout << "\n=========================" << std::endl;
    std::cout << "      ZOO PROJEKT        " << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "1. Nova hra" << std::endl;
    std::cout << "2. O autorech" << std::endl;
    std::cout << "0. Konec" << std::endl;
    std::cout << "=========================" << std::endl;
}

void Menu::runGameLoop() {
    std::cout << "\n--- Start Hry ---" << std::endl;

    // Zde přesuneme kód, co jsi měl předtím v main.cpp
    if (m_map == nullptr) {
        m_map = new Map(5, 5);
        m_map->placeTile(2, 2, new Hallway(true, true, true, false));
    }

    // Ukázka práce s mapou
    Tile* t = m_map->getTile(2, 2);
    if (t != nullptr) {
        std::cout << "Vykresluji dlazdici na 2,2:" << std::endl;
        t->printTile(true);

        // Tady by pak byl další while cyklus pro pohyb hrdiny
        // while(playing) { ... input w/a/s/d ... }
    }

    std::cout << "Hra skoncila (zatim jen ukazka)." << std::endl;

    // Mapu můžeme smazat hned, nebo si ji nechat v paměti pro příště
    delete m_map;
    m_map = nullptr;
}