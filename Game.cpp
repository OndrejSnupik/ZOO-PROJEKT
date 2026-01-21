#include "Game.h"

void Game::run() {
    while (m_menuRunning) {
        MenuAction action = m_menu->run();

        switch (action) {
            case MenuAction::startNewGame :{
                m_difficulty = m_menu->chooseDifficulty();
                setUpNewGame(); // delete old game and start new one
                runGameLoop(); // run game
                break;
            }
            case MenuAction::showCredits: m_menu->showCredits();
                break;
                case MenuAction::quit:
                m_menuRunning = false;
                break;
        }
    }
}

void Game::runGameLoop() {
    m_redraw = true; //redraw the UI when movement happens true= redraw UI or false= skip redraw
    std::cout << "--- HRA ZACINA ---" << std::endl;

    // Hlavní herní smyčka
    while (m_gameRunning) {
        // if a key is pressed then redraw UI
        if (handleInput()) {
            m_redraw = true;
        }

        if (m_redraw) { // if redraw is true
            system("cls"); // clear screen

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
            m_redraw = false;

            //check for combat
            Tile * tile = m_map->getTile(m_hero->getX(), m_hero->getY());
            // redraw Ui if combat is true
            if (checkForCombat(tile)){
                m_redraw = true;
                continue;
            }
        }
    }
}

void Game::setUpNewGame() {
    // Delete old objects
    delete m_map;
    delete m_hero;
    //delete m_enemyFactory;

    // Vytvoří mapu a hrdinu
    m_map = new Map(20, 20);
    m_hero = new Hero(10, 10, 100, 30);
    //stored position so that hero can be pushed back to previous tile when running away.
    m_lastHeroX = m_hero->getX();
    m_lastHeroY = m_hero->getY();

    m_map->placeTile(10, 10, new Hallway(true, true, true, true));

    if (m_difficulty == 1) {
        m_enemyFactory = new EasyEnemyFactory();
    } else {
        m_enemyFactory = new HardEnemyFactory();
    }

    m_dragonSpawned = false;
    m_gameRunning = true;
    m_redraw = true;
}



Game::Game() {
    // generátor náhodných čísel
    std::srand(std::time(nullptr));
    //vytvoří menu
    m_menu = new Menu();

    m_difficulty = 0;
    m_enemyFactory = nullptr;
    m_enemy = nullptr;
    m_map = nullptr;
    m_hero = nullptr;
    m_dragonSpawned = false;
    m_menuRunning = true;
    m_gameRunning = false;
    m_redraw = false;
    m_lastHeroX = 0;
    m_lastHeroY = 0;
}

Game::~Game() {
    delete m_menu;
    delete m_map;
    delete m_hero;
    delete m_enemyFactory;
}

bool Game::handleInput() {
    if (!_kbhit()) {
        return false; // no key pressed, skip this frame
    }

    char input = _getch(); // read key
    int currentX = m_hero->getX();
    int currentY = m_hero->getY();
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
            if (currentTile->hasExit(1)) { // Kontrola jihu
                targetY++;
            }else {
                std::cout << "Au! Narazil jsi do zdi.\n";
                return false;
            }
            break;

        case 'a':
            if (currentTile->hasExit(2)) { // Kontrola západu
                targetX--;
            }else {
                std::cout << "Au! Narazil jsi do zdi.\n";
                return false;
            }
            break;

        case 'd':
            if (currentTile->hasExit(3)) { // Kontrola východu
                targetX++;
            }else {
                std::cout << "Au! Narazil jsi do zdi.\n";
                return false;
            }
            break;

        case 'q': //end current game and back to menu
            m_gameRunning = false;
            return true;

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
bool Game::checkForCombat(Tile *tile) {
    // If tile is empty or no enemy in the tile then no combat
    if (tile == nullptr || tile->getEnemy() == nullptr ){
        return false;
    }
    CombatSystem combat(m_hero, tile->getEnemy());
    CombatResult result = combat.run();
    handleCombatResult(result, tile, tile->getEnemy());
    // If combat ended or changed the tile, then redraw
    return true;
}

void Game::handleCombatResult(CombatResult result, Tile *tile, Enemy *enemy) {
    switch (result) {
        case CombatResult::HeroDied:
            std::cout << "---------------------\n";
            std::cout << "Zemrel jsi" << std::endl;
            std::cout << "---------------------\n";
            m_gameRunning = false;
            break;
        case CombatResult::HeroRan:
            std::cout << "---------------------\n";
            std::cout << "Utekl jsi z boje!\n";
            std::cout << "---------------------\n";
            //move back to previous tile
            m_hero->setPosition(m_lastHeroX, m_lastHeroY);
            break;
        case CombatResult::EnemyDied:
            std::cout << "---------------------\n";
            std::cout << "Porazil jsi nepratele" << std::endl;
            std::cout << "---------------------\n";
            delete enemy;
            tile->setEnemy(nullptr);
            break;
        case CombatResult::DragonDied:
            std::cout << "---------------------\n";
            std::cout << "Vyhral jsi!!!" << std::endl;
            std::cout << "---------------------\n";
            delete enemy;
            tile->setEnemy(nullptr);
            m_gameRunning = false;
        default:
            std::cout << "Neplatna volba." << std::endl;
            break;
    }
}

