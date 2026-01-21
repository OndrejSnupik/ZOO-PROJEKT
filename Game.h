//
// Created by ondra on 10/12/2025.
//

#ifndef ZOO_PROJEKT_GAME_H
#define ZOO_PROJEKT_GAME_H
#include "CombatSystem.h"
#include "Menu.h"
#include "Hero.h"
#include "Map.h"
#include "EnemyFactory/Enemy.h"
#include "EnemyFactory/EnemyFactory.h"
#include "EnemyFactory/EasyEnemyFactory.h"
#include  "EnemyFactory/HardEnemyFactory.h"
#include "Hallway.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> // for _kbhit() and _getch()
#include <windows.h> // for Sleep()

class Game {
    private:
    Menu * m_menu;
    Map* m_map;
    Hero* m_hero;
    Enemy* m_enemy;
    EnemyFactory* m_enemyFactory;
    bool m_gameRunning;// Indikuje jestli herní smyčka běží
    bool m_menuRunning;
    int m_difficulty;
    bool m_dragonSpawned;
    //stored hero previous tile
    int m_lastHeroX;
    int m_lastHeroY;
    bool m_redraw; // clear screen and redraw if true


    bool handleInput(); // vstupy z klávesnice
    void generateRandomTile(int x, int y, int incomingDirection); // Generuje novou místnost
    Enemy* spawnEnemy();
    bool checkForCombat(Tile* tile); // run combat system when true
    void handleCombatResult(CombatResult result, Tile* tile, Enemy* enemy);
    void runGameLoop();
    void setUpNewGame();
public:
    Game();
    ~Game();
    void run(); // Spouští hlavní cyklus hry
};


#endif //ZOO_PROJEKT_GAME_H