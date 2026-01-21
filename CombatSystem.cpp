//
// Created by hoang on 24/12/2025.
//

#include "CombatSystem.h"

CombatSystem::CombatSystem(Hero *hero, Enemy *enemy) {
    m_hero = hero;
    m_enemy = enemy;
    m_result = CombatResult::None;
}

void CombatSystem::run() {
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
            return handleFlee();
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
    std::cout << "     ";
    std::cout << "Enemy: " << m_enemy->getName()<< "\n";
    std::cout << "Heath: " << m_hero->getHp();
    std::cout << "               ";
    std::cout << "Heath: " << m_enemy->getHeath()<< "\n";
    std::cout << "AttackDMG: " << m_hero->getAttack();
    std::cout << "            ";
    std::cout << "AttackDMG: " << m_enemy->getAttack()<< "\n";
    std::cout << "\n";
    std::cout << "=====Hero=====" << "\n";
    std::cout << "1. Normalni utok " << "\n";
    //std::cout << "2. Use Special Skill " << "\n";
    //std::cout << "3. Use Scroll " << "\n";
    //std::cout << "4. Use Healing poition " << "\n";
    std::cout << "0. Utect " << "\n";
    std::cout << "Vyber akci: ";
}

void CombatSystem::handleCombat() {
    while (true) {
        //system("cls");
        drawCombatUI();

        heroTurn();
        //
        if (m_result == CombatResult::HeroRan) {
            return;
        }

        //update duration when hero turn has ended
        m_hero->updateState();
        //check
        if (m_enemy->getSymbol() == 'D' && m_enemy->getHeath() <= 0) {
            m_result = CombatResult::DragonDied;
            return;
        }

        if (m_enemy->getHeath() <= 0) {
            m_result = CombatResult::EnemyDied;
            return;
        }
        //enemy turn
        enemyAttack();
        if (m_hero->getHp() <= 0) {
            m_result = CombatResult::HeroDied;
            return;
        }


    }
}

void CombatSystem::handleFlee() {
    //50% chance to flee without taking dmg
    if (std::rand() % 2 == 0) {
        std::cout <<"------------------------------\n";
        std::cout << "Utekl jsi" << std::endl;
        m_result = CombatResult::HeroRan;
        return;
    }
    //enemy hit once before you ran away.
    std::cout <<"------------------------------\n";
    std::cout << "Utekl jsi ale..." << std::endl;
    enemyAttack();

    if (m_hero->getHp() <= 0) {
        m_result =  CombatResult::HeroDied;
    }else {
        m_result =  CombatResult::HeroRan;
    }
}

void CombatSystem::normalAttack() {
    int newEnemyHeath = m_enemy->getHeath() - m_hero->getAttack();
    m_enemy->setHeath(newEnemyHeath);
    std::cout <<"------------------------------\n";
    std::cout << m_hero->getName() << " zasahl za "
              << m_hero->getAttack() << " dmg." << std::endl;
}

void CombatSystem::enemyAttack() {
    //basic attack
    int newHeroHeath = m_hero->getHp() - m_enemy->getAttack();
    m_hero->setHp(newHeroHeath);
    std::cout <<"------------------------------\n";
    std::cout << m_enemy->getName() << " te zasahl za "
              << m_enemy->getAttack() << " dmg." << std::endl;
    //debuff
    int roll = std::rand() % 100;
    if (roll < m_enemy->getDebuffChance()) {
            if (m_enemy->getDebuff() == DebuffType::Weaken) {
                m_hero->setState(new WeakenState());
            }else if (m_enemy->getDebuff() == DebuffType::Stun){
                m_hero->setState(new StunnedState());
            }
    }
}

void CombatSystem::heroTurn() {
    //hero loses turn
    if (m_hero->isStunned()) {
        std::cout <<"\n------------------------------\n";
        std::cout << "Jsi omracen a nemuzes utocit!" << std::endl;
        return;
    }

    while (true) {
        int choice;

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Neplatny vstup!" << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                normalAttack();
                return;
                // case 2:
                //     //useSkills();
                //     break;
                // case 3:
                //     //useScroll();
                //     break;
                // case 4:
                //     //useHealingPotion();
                //     break;
            case 0:
                handleFlee();
                return;
            default:
                std::cout << "Neplatna volba." << std::endl;
                break;
        }
    }
}

CombatResult CombatSystem::getCombatResult() {
    return m_result;
}