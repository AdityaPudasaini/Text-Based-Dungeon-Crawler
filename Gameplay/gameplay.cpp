#include <iostream>
#include <random>

#include "Gameplay.h" 

Gameplay::Gameplay() {

}

Gameplay::Gameplay(Player player, commonEnemy enemy) {
    this->player = player;
    this->enemy = enemy;
}

std::string Gameplay::getPlayerDecision() const {
    return playerDecision;
}

std::string Gameplay::getAttackName() const {
    return attackName;
}

std::string Gameplay::getPotionName() const {
    return potionName;
}

std::string Gameplay::getAttackType() const {
    return attackType;
}

void Gameplay::setPlayerDecision(std::string playerDecision) {
    this->playerDecision = playerDecision;
}

void Gameplay::setAttackName(std::string attackName) {
    this->attackName = attackName;
}

void Gameplay::setPotionName(std::string potionName) {
    this->potionName = potionName;
}

void Gameplay::setAttackType(std::string attackType) {
    this->attackType = attackType;
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
    std::cout << "Choose the form of attack you want to use: (1 for Physical/ 2 for Magic): ";
    std::cin >> attackType;

    int attackTypeInt = std::stoi(attackType);

    if(attackTypeInt == 1) {
        attackName = "Sword Attack";
        playerAttack();
    }

    else if(attackTypeInt == 2) {
        attackName = "Fireball";
        playerAttack();
    }

    else {
        std::cout << "Invalid input. Enter a valid input." << std::endl;
        attackTypeSelection();
    }
}

void Gameplay::playerAttack() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist (1, 10);

    int damage = dist(gen);

    int enemyHealth = enemy.getHealth();
    enemyHealth = enemyHealth - damage;

    if(enemyHealth!=0) {
        enemyAttack();
    }

    else {
        newLevel();
    }
}

void Gameplay::enemyAttack() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist (1, 6);

    int damage = dist(gen);

    int playerHealth = player.getHealth();
    playerHealth = playerHealth - damage;

    if(playerHealth!=0) {
        decisionToAttackOrUsePotion();
    }

    else {
        return;
    }

}

void Gameplay::newLevel () {
    int i = 1;

    if(i < 10) {
        std::cout << "You are in level" << i << std::endl;
        decisionToAttackOrUsePotion();
    }

    else {
        return;
    }

}

void Gameplay::playerUsePotion() {
    std::cout << "You used a potion! Health restored." << std::endl;
    player.setHealth(player.getHealth() + 20);
    displayHealthStatus();
    enemyAttack();
}

void Gameplay::displayHealthStatus() const {
    std::cout << "Player HP: " << player.getHealth() << std::endl;
    std::cout << "Enemy HP: " << enemy.getHealth() << std::endl;
}

float Gameplay::calculateDamage(float attackDamage) {
    return attackDamage;
}
