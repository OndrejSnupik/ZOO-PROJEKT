//
// Created by hoang on 24/12/2025.
//

#include "CombatSystem.h"

CombatSystem::CombatSystem(Hero *hero, Enemy *enemy) {
    m_hero = hero;
    m_enemy = enemy;
}

CombatResult CombatSystem::run() {
    while (true) {
        draw();
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Neplatny vstup!" << std::endl;
            continue;
        }

        if (choice == 1) {
            return handleCombat();
        }
        if (choice == 0) {
            return handleRun();
        }

        std::cout << "Neplatna volba." << std::endl;
    }
}

void CombatSystem::draw() {
    std::cout << "\n" << "===== BOJ ======" << "\n";
    std::cout << "Narazil jsi na " << m_enemy->getSymbol() << "\n";
    std::cout << "1. Bojovat " << "\n";
    std::cout << "0. Utect " << "\n";
    std::cout << "Vyber akci: ";
}

void CombatSystem::drawCombatUI() {
    std::cout << "\n" << "===== IN COMBAT ======" << "\n";
    std::cout << "Hero: " << m_hero->getName();
    std::cout << "                   ";
    std::cout << "Enemy: " << m_enemy->getSymbol()<< "\n";
    std::cout << "Heath: " << m_hero->getHp();
    std::cout << "               ";
    std::cout << "Heath: " << m_enemy->getHeath()<< "\n";
    std::cout << "AttackDMG: " << m_hero->getBaseAttack();
    std::cout << "            ";
    std::cout << "AttackDMG: " << m_enemy->getAttack()<< "\n";
    std::cout << "\n";
    std::cout << "=====Hero=====" << "\n";
    std::cout << "1. Use normal Attack " << "\n";
    std::cout << "2. Use Special Skill " << "\n";
    std::cout << "3. Use Scroll " << "\n";
    std::cout << "4. Use Healing poition " << "\n";
    std::cout << "0. Utect " << "\n";
    std::cout << "Vyber akci: ";
}

CombatResult CombatSystem::handleCombat() {
    while (m_enemy->getHeath() > 0 && m_hero->getHp() > 0) {
        drawCombatUI();
        int choice;

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Neplatny vstup!" << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                useBasicAttack();
                break;
            case 2:
                //useSkills();
                break;
            case 3:
                //useScroll();
                break;
            case 4:
                //useHealingPotion();
                break;
            case 0:
                return handleRun();
            default:
                std::cout << "Neplatna volba." << std::endl;
                break;
        }
    }

    if (m_hero->getHp() <= 0) {
        return CombatResult::HeroDied;
    }

    if (m_enemy->getSymbol() == 'D' && m_enemy->getHeath() <= 0) {
        return CombatResult::DragonDied;
    }
    return CombatResult::EnemyDied;
}

CombatResult CombatSystem::handleRun() {
    if (std::rand() % 2 == 0) {
        std::cout << "Utekl jsi" << std::endl;
        return CombatResult::HeroRan;
    }

    std::cout << "Utekl jsi ale..." << std::endl;
    //enemy hit once before you ran away.
    int newHeroHeath = m_hero->getHp() - m_enemy->getAttack();
    m_hero->setHp(newHeroHeath);
    std::cout << m_enemy->getSymbol() << " te zasahl za "
              << m_enemy->getAttack() << " dmg." << std::endl;
    if (newHeroHeath <= 0) {
        return CombatResult::HeroDied;
    }
    return CombatResult::HeroRan;
}

void CombatSystem::useBasicAttack() {
    int newEnemyHeath = m_enemy->getHeath() - m_hero->getBaseAttack();
    m_enemy->setHeath(newEnemyHeath);
    std::cout << m_hero->getName() << " zasahl za "
              << m_hero->getBaseAttack() << " dmg." << std::endl;

    if (newEnemyHeath <= 0) {
        return;
    }

    int newHeroHeath = m_hero->getHp() - m_enemy->getAttack();
    m_hero->setHp(newHeroHeath);
    std::cout << m_enemy->getSymbol() << " te zasahl za "
              << m_enemy->getAttack() << " dmg." << std::endl;
}
