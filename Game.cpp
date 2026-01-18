#include "Game.h"

Game::Game(int difficulty) {
    // generátor náhodných čísel
    std::srand(std::time(nullptr));

    m_difficulty = difficulty;
    if (difficulty == 1) {
        m_enemyFactory = new EasyEnemyFactory();
    } else {
        m_enemyFactory = new HardEnemyFactory();
    }
    m_enemy = nullptr;

    // Vytvoří mapu a hrdinu
    m_map = new Map(20, 20);
    m_hero = new Hero(10, 10, 100, 30);
    m_lastHeroX = m_hero->getX();
    m_lastHeroY = m_hero->getY();

    //Vloží startovní dlaždici doprostřed mapy
    m_map->placeTile(10, 10, new Hallway(true, true, true, true));

    m_isRunning = true;
    m_dragonSpawned = false;

}

Game::~Game() {
    delete m_map;
    delete m_hero;
    delete m_enemy;
}

void Game::run() {
    bool redraw = true; //redraw the UI when movement happens true= redraw UI or false= skip redraw
    std::cout << "--- HRA ZACINA ---" << std::endl;

    // Hlavní herní smyčka
    while (m_isRunning) {
        if (redraw) {
            system("cls");
            for(int i=0; i<3; i++) std::cout << "\n";
            int x = m_hero->getX();
            int y = m_hero->getY();
            Tile* currentTile = m_map->getTile(x, y);

            std::cout << "Pozice: [" << x << "," << y << "] | Zivoty: " << m_hero->getHp();
            std::cout <<" Attack: "<< m_hero->getBaseAttack() << std::endl;

            if (currentTile != nullptr) {
                currentTile->printTile(true);
            } else {
                std::cout << "CHYBA: Stojis v prazdnu!" << std::endl;
            }
            std::cout << "Ovladani: [w] Sever, [s] Jih, [a] Zapad, [d] Vychod, [q] Konec" << std::endl;
            redraw = false;
            //check for combat
            Tile * tile = m_map->getTile(m_hero->getX(), m_hero->getY());
            checkForCombat(tile);
        }
        if (handleInput()) {
            redraw = true; // redraw new tile
            continue;
        }
        Sleep(30);

    }
}

bool Game::handleInput() {
    if (!_kbhit()) {
        return false; // no key pressed, skip this frame
    }

    char input = _getch(); // read key immediately
    int currentX = m_hero->getX();
    int currentY = m_hero->getY();
    //hero can be pushed back to previous tile when running away.
    m_lastHeroX = currentX;
    m_lastHeroY = currentY;
    Tile* currentTile = m_map->getTile(currentX, currentY);
    int targetX = currentX;
    int targetY = currentY;

    // Směr pohybu podle klávesy
    switch (input) {
        case 'w': // Kontrola jeslti vede cesta na sever
            if (currentTile->hasExit(0)) {
                targetY--;
            }else {
                std::cout << "Au! Narazil jsi do zdi.\n";
                return false;
            }
            break;

        case 's':
            if (currentTile->hasExit(1)) {
                targetY++; // Kontrola jihu
            }else {
                std::cout << "Au! Narazil jsi do zdi.\n";
                return false;
            }
            break;

        case 'a':
            if (currentTile->hasExit(2)) {
                targetX--; // Kontrola západu
            }else {
                std::cout << "Au! Narazil jsi do zdi.\n";
                return false;
            }
            break;

        case 'd':
            if (currentTile->hasExit(3)) {
                targetX++; // Kontrola východu
            }else {
                std::cout << "Au! Narazil jsi do zdi.\n";
                return false;
            }
            break;

        case 'q': // Ukončí hru
            m_isRunning = false;
            return false;

        default:
            return false;
    }
    // Zkontroluje jestli se hráč nesnaží vyjít mimo hranice mapy
    if (targetX < 0 || targetX >= m_map->getWidth() ||
        targetY < 0 || targetY >= m_map->getHeight()) {
        std::cout << "Tam nemuzes, to je konec sveta!\n";
        return false;
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
    // Only return true if hero actually moved
    if (targetX != currentX || targetY != currentY) {
        return true;
    }
    return false;
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
        //spawn enemy randomly
        Enemy* enemy = spawnEnemy();
        newTile->setEnemy(enemy);

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

Enemy* Game::spawnEnemy() {
    unsigned int roll = std::rand() % 100;

    //6 % chance for dragon to spawn
    //there is only 1 Dragon on the game
    //on defeating the Dragon the game will end
    if (roll <= 6 && !m_dragonSpawned) {
        m_dragonSpawned= true;
        return m_enemyFactory->getDragon();
    }
    //30 % chance for no enemy
    if (roll > 6 && roll <= 36){
        return nullptr;
    }
    // 64% chance for normal enemy
    if (roll > 36) {
        unsigned int r = std::rand() % 3;
        if (r == 0) return m_enemyFactory->getZombie();
        if (r == 1) return m_enemyFactory->getSkeleton();
        return m_enemyFactory->getTroll();
    }
    return nullptr;
}
// Combat check - open combat screen if there is an enemy
void Game::checkForCombat(Tile *tile) {
    if (tile == nullptr || tile->getEnemy() == nullptr ){
        return;
    }
    Sleep(2000);
    CombatSystem combat(m_hero, tile->getEnemy());
    CombatResult result = combat.run();
    handleCombatResult(result, tile, tile->getEnemy());
}

void Game::handleCombatResult(CombatResult result, Tile *tile, Enemy *enemy) {
    switch (result) {
        case CombatResult::EnemyDied:
            std::cout << "Porazil jsi nepratele" << std::endl;
            delete enemy;
            tile->setEnemy(nullptr);
            break;
        case CombatResult::HeroDied:
            std::cout << "Zemrel jsi" << std::endl;
            m_isRunning = false;
            break;
        case CombatResult::HeroRan:
            std::cout << "Utekl jsi z boje!\n";
            //move back to previous tile
            m_hero->setPosition(m_lastHeroX, m_lastHeroY);
            break;
    }
}
