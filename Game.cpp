#include "Game.h"
#include "Hallway.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game() {
    // generátor náhodných čísel
    std::srand(std::time(nullptr));

    // Vytvoří mapu a hrdinu
    m_map = new Map(20, 20);
    m_hero = new Hero(10, 10, 100);

    //Vloží startovní dlaždici doprostřed mapy
    m_map->placeTile(10, 10, new Hallway(true, true, true, true));

    m_isRunning = true;
}

Game::~Game() {
    delete m_map;
    delete m_hero;
}

void Game::run() {
    std::cout << "--- HRA ZACINA ---" << std::endl;

    // Hlavní herní smyčka
    while (m_isRunning) {
        for(int i=0; i<3; i++) std::cout << "\n";

        int x = m_hero->getX();
        int y = m_hero->getY();
        Tile* currentTile = m_map->getTile(x, y);

        std::cout << "Pozice: [" << x << "," << y << "] | Zivoty: " << m_hero->getHp() << std::endl;

        if (currentTile != nullptr) {
            currentTile->printTile(true);
        } else {
            std::cout << "CHYBA: Stojis v prazdnu!" << std::endl;
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

    // Směr pohybu podle klávesy
    switch (input) {
        case 'w':
            if (currentTile->hasExit(0)) { // Kontrola jeslti vede cesta na sever
                targetY--;
            } else {
                std::cout << "Au! Narazil jsi do zdi." << std::endl;
                std::cin.ignore(); std::cin.get();
                return;
            }
            break;

        case 's':
            if (currentTile->hasExit(1)) { // Kontrola jihu
                targetY++;
            } else {
                std::cout << "Au! Narazil jsi do zdi." << std::endl;
                std::cin.ignore(); std::cin.get();
                return;
            }
            break;

        case 'a':
            if (currentTile->hasExit(2)) { // Kontrola západu
                targetX--;
            } else {
                std::cout << "Au! Narazil jsi do zdi." << std::endl;
                std::cin.ignore(); std::cin.get();
                return;
            }
            break;

        case 'd':
            if (currentTile->hasExit(3)) { // Kontrola východu
                targetX++;
            } else {
                std::cout << "Au! Narazil jsi do zdi." << std::endl;
                std::cin.ignore(); std::cin.get();
                return;
            }
            break;

        case 'q': // Ukončí hru
            m_isRunning = false;
            return;

        default:
            return;
    }

    // Zkontroluje jestli se hráč nesnaží vyjít mimo hranice mapy
    if (targetX < 0 || targetX >= m_map->getWidth() || targetY < 0 || targetY >= m_map->getHeight()) {
        std::cout << "Tam nemuzes, to je konec sveta!" << std::endl;
        std::cin.ignore(); std::cin.get();
        return;
    }

    // Pokud na cílovém políčku nic není vygeneruje novou dlaždici
    if (m_map->getTile(targetX, targetY) == nullptr) {

        int requiredEntry = -1;

        // Určí ze které strany hrdina přichází, aby na sebe cesty navazovaly
        if (targetY < currentY) requiredEntry = 1;
        else if (targetY > currentY) requiredEntry = 0;
        else if (targetX < currentX) requiredEntry = 3;
        else if (targetX > currentX) requiredEntry = 2;

        generateRandomTile(targetX, targetY, requiredEntry);
    }

    // Pokud je cílové políčko platné, přesune tam hrdinu
    if (m_map->getTile(targetX, targetY) != nullptr) {
        m_hero->setPosition(targetX, targetY);
    }
}

void Game::generateRandomTile(int x, int y, int incomingDirection) {
    // Zkusí 10x vygenerovat náhodnou dlaždici, která sedí
    for (int pokus = 0; pokus < 10; pokus++) {

        bool r1 = std::rand() % 2;
        bool r2 = std::rand() % 2;
        bool r3 = std::rand() % 2;
        bool r4 = std::rand() % 2;

        // Zajistí, aby místnost nebyla úplně uzavřená
        if (!r1 && !r2 && !r3 && !r4) r1 = true;

        Tile* newTile = new Hallway(r1, r2, r3, r4);

        bool fits = false;
        // Bude dlaždici otáčet, dokud nenajde polohu, která navazuje na vstup
        for (int i = 0; i < 4; i++) {
            if (newTile->hasExit(incomingDirection)) {
                fits = true;
                break;
            }
            newTile->rotate();
        }

        if (fits) {
            m_map->placeTile(x, y, newTile);
            return;
        } else {
            delete newTile; // Pokud nepasuje smaže ji a zkusí to znovu
        }
    }

    // Pokud se nepodaří najít náhodnou dlazdici , vloží křižovatku
    m_map->placeTile(x, y, new Hallway(true, true, true, true));
}