//
// Created by ondra on 10/12/2025.
//

#ifndef ZOO_PROJEKT_GAME_H
#define ZOO_PROJEKT_GAME_H
#include "Hero.h"
#include "Map.h"
#include "EnemyFactory/Enemy.h"
#include "EnemyFactory/EnemyFactory.h"
#include "EnemyFactory/EasyEnemyFactory.h"
#include  "EnemyFactory/HardEnemyFactory.h"

class Game {
    private:
    Map* m_map;
    Hero* m_hero;
    Enemy* m_enemy;
    EnemyFactory* m_enemyFactory;
    bool m_isRunning; // Indikuje jestli herní smyčka běží
    int m_difficulty;
    bool m_dragonSpawned;

    void handleInput(); // vstupy z klávesnice
    void generateRandomTile(int x, int y, int incomingDirection); // Generuje novou místnost
    Enemy* spawnEnemy();
public:
    Game(int difficulty);
    ~Game();
    void run(); // Spouští hlavní cyklus hry
};


#endif //ZOO_PROJEKT_GAME_H