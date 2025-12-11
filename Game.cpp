//
// Created by ondra on 10/12/2025.
//

#include "Game.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Hallway.h"

Game::Game() {
    std::srand(std::time(nullptr));
    m_map = new Map(20, 20);
    m_hero = new Hero(10, 10, 100);
    m_map->placeTile(10, 10, new Hallway(true, true, true, true));
    m_isRunning = true;
}

Game::~Game() {
    delete m_map;
    delete m_hero;
}

void Game::run() {
    std::cout << "--- ZACATEK HRY ---" << std::endl;

    while (m_isRunning) {
        for (int i=0; i<50; i++) {
            std::cout << "\n";
        }
        int x = m_hero->getX();
        int y = m_hero->getY();
        Tile* tile = m_map->getTile(x, y);

        std::cout << "Pozice: [" << x << "," << y << "] Zivoty: " << m_hero->getHp() << std::endl;
        if (tile != nullptr) {
            tile->printTile(true);
        }else {
            std::cout << "Chyba generovani" << std::endl;
        }
        std::cout << "Ovladani: [w] Sever, [s] Jih, [a] Zapad, [d] Vychod, [q] Konec" << std::endl;

        handleInput();
    }

}
void Game::handleInput() {
    char input;
    std::cout << "> ";
    std::cin >> input;

    int currentX = m_hero->getX();
    int currentY = m_hero->getY();

    Tile* currentTile = m_map->getTile(currentX, currentY);

    int targetX = currentX;
    int targetY = currentY;

    switch (input) {
        case 'w':
            if (currentTile->hasExit(0)) {
                targetY--;
            } else {
                std::cout << "Narazil jsi do zdi, tady cesta nevede" << std::endl;
                std::cin.ignore(); std::cin.get();
                return;
            }
            break;

        case 's':
            if (currentTile->hasExit(1)) {
                targetY++;
            } else {
                std::cout << "Narazil jsi do zdi, tady cesta nevede" << std::endl;
                std::cin.ignore(); std::cin.get();
                return;
            }
            break;

        case 'a':
            if (currentTile->hasExit(2)) {
                targetX--;
            } else {
                std::cout << "Narazil jsi do zdi, tady cesta nevede" << std::endl;
                std::cin.ignore(); std::cin.get();
                return;
            }
            break;

        case 'd':
            if (currentTile->hasExit(3)) {
                targetX++;
            } else {
                std::cout << "Narazil jsi do zdi, tady cesta nevede" << std::endl;
                std::cin.ignore(); std::cin.get();
                return;
            }
            break;

        case 'q':
            m_isRunning = false;
            return;

        default:
            return;
    }

    if (targetX < 0 || targetX >= m_map->getWidth() || targetY < 0 || targetY >= m_map->getHeight()) {
        std::cout << "Mimo mapu" << std::endl;
        std::cin.ignore(); std::cin.get();
        return;
    }
    if (m_map->getTile(targetX, targetY) == nullptr) {
        generateRandomTile(targetX, targetY);
    }
    if (m_map->getTile(targetX, targetY) != nullptr) {
        m_hero->setPosition(targetX, targetY);
    }
}
void Game::generateRandomTile(int x, int y) {
    // Jednoduchá generace: Náhodně určíme zdi
    bool r1 = std::rand() % 2;
    bool r2 = std::rand() % 2;
    bool r3 = std::rand() % 2;
    bool r4 = std::rand() % 2;

    // Vytvoříme novou chodbu
    // Pozor: Tady by se v budoucnu měla dělat kontrola, jestli navazuje na sousedy!
    // Pro teď to necháme náhodné, aby kód nebyl moc složitý.
    Tile* newTile = new Hallway(r1, r2, r3, r4);

    // Vložíme do mapy
    m_map->placeTile(x, y, newTile);
}


