#include "commonEnemy.h"

commonEnemy::commonEnemy() {
    health = 100;
    attackDamage = 10;
    isDefeated = false;
}

commonEnemy::commonEnemy(float health, float attackDamage, bool isDefeated) {
    this -> health = health;
    this -> attackDamage = attackDamage;
    this -> isDefeated = isDefeated;
}
