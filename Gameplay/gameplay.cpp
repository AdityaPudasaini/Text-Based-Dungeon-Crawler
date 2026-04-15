#include <iostream>
#include <random>

#include "Gameplay.h" 

Gameplay::Gameplay() {

}

Gameplay::Gameplay(Player player, commonEnemy enemy, bossEnemy boss) {
    this->player = player;
    this->enemy = enemy;
    this->boss = boss;
}

void Gameplay::decisionToAttackOrUsePotion() {
    std::cout << "Do you want to attack or use a potion? (1 for Attack/2 for Potion): ";
    int playerDecionInt;
    std::cin >> playerDecionInt;

    if(playerDecionInt == 1) {
        attackTypeSelection();    
    }

    else if(playerDecionInt == 2) {
        playerUsePotion();
    }

    else {
        std::cout << "Invalid input. Enter a valid input." << std::endl;
        decisionToAttackOrUsePotion();
    }
}

void Gameplay::attackTypeSelection() {
    std::cout << std::endl;
    std::cout << "Choose the form of attack you want to use: (1 for Physical/ 2 for Magic): ";
    
    int attackTypeInt;
    std::cin >> attackTypeInt;


    if(attackTypeInt == 1) {
        playerPhysicalAttack();
    }

    else if(attackTypeInt == 2) {
        playerMagicAttack();
    }

    else {
        std::cout << "Invalid input. Enter a valid input." << std::endl;
        attackTypeSelection();
    }
}

void Gameplay::playerMagicAttack() {
    if(player.getMana() >= 5) {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> dist (10, 26);

        int damage = dist(gen);

        int newMana = player.getMana() - 5;
        player.setMana(newMana);

        if(isBossFight == false) {
            int enemyHealth = enemy.getHealth();
            enemyHealth = enemyHealth - damage;
            enemy.setHealth(enemyHealth);

            if(enemyHealth > 0) {
                enemyAttack(enemyHealth);
            }

            else {
                newLevel();
            }
        }

        else {
            int bossHealth = boss.getHealth();
            bossHealth = bossHealth - damage;
            boss.setHealth(bossHealth);

            if(bossHealth > 0) {
                enemyAttack(bossHealth);
            }

            else {
                newLevel();
            }
        }
    }

    else {
        std::cout << "Not enough mana." << std::endl;
        decisionToAttackOrUsePotion();
    }
}

void Gameplay::playerPhysicalAttack() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist (1, 10);

    int damage = dist(gen);

    if(isBossFight == false) {
        int enemyHealth = enemy.getHealth();
        enemyHealth = enemyHealth - damage;
        enemy.setHealth(enemyHealth);

        if(enemyHealth > 0) {
            enemyAttack(enemyHealth);
        }

        else {
            newLevel();
        }
    }

    else {
        int bossHealth = boss.getHealth();
        bossHealth = bossHealth - damage;
        boss.setHealth(bossHealth);

        if(bossHealth > 0) {
            bossAttack();
        }

        else {
            std::cout << "Congratulation you completed the game" << std::endl;
        }
    }
}

void Gameplay::bossAttack() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist (10, 30);

    int damage = dist(gen);

    int playerHealth = player.getHealth();
    playerHealth = playerHealth - damage;
    player.setHealth(playerHealth);

    if(playerHealth > 0) {
        displayHealthStatus();
        decisionToAttackOrUsePotion();
    }

    else {
        std::cout << "You died" << std::endl;
        return;
    }
}

void Gameplay::enemyAttack(int enemyHealth) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist (1, 6);

    int damage = dist(gen);

    int playerHealth = player.getHealth();
    playerHealth = playerHealth - damage;
    player.setHealth(playerHealth);

    if(playerHealth > 0) {
        displayHealthStatus();
        decisionToAttackOrUsePotion();
    }

    else {
        std::cout << "You died" << std::endl;
        return;
    }

}

void Gameplay::newLevel () {
    level++;

    std::cout << "Level Clearled" << std::endl;
    std::cout << "You are in level " << level  << " now." << std::endl;
    std::cout << std::endl;

    if(level < 10) {
        enemy.resetEnemy();

        decisionToAttackOrUsePotion();
    }

    else {
        std:: cout << "Now its time for boss fight" << std::endl;
        isBossFight = true;
        decisionToAttackOrUsePotion();
    }

}

void Gameplay::playerUsePotion() {
    std::cout << "What kind of potion you want to use? 1 for health & 2 for mana" << std::endl;
    int potionChoice{};
    std::cin >> potionChoice;

    if(potionChoice == 1) {
        healthPotionCount --;
        std::cout << "You used a health potion! Health restored." << std::endl;
        std::cout << "You have " << healthPotionCount << " potions remaining." << std::endl;
        player.setHealth(player.getHealth() + 20);
        displayHealthStatus();
        enemyAttack(enemyHealth);
    }

    else if(potionChoice == 2) {
        manaPotionCount --;
        std::cout << "You used a mana potion. Mana restored" << std::endl;
        std::cout << "You have " << manaPotionCount << " potion remaining." << std::endl;
        player.setMana(player.getMana() + 7);
        enemyAttack(enemyHealth);
    }

    else {
        std::cout << "Invalid choice" << std::endl;
        decisionToAttackOrUsePotion();
    }
}

void Gameplay::displayHealthStatus() const {
    std::cout << "Player HP: " << player.getHealth() << std::endl;
    std::cout << "Enemy HP: " << enemy.getHealth() << std::endl;
}

float Gameplay::calculateDamage(float attackDamage) {
    return attackDamage;
}
