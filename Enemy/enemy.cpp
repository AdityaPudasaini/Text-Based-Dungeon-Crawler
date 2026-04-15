#include "Enemy.h"

Enemy::Enemy() {
    health = 0;
    attackDamage = 0;
}

Enemy::Enemy(float health, float attackDamage) {
    this->health = health;
    this->attackDamage = attackDamage;
}

float Enemy::getHealth() const { 
    return health;
}

float Enemy::getAttackDamage() const{
    return attackDamage;
}

void Enemy::setHealth(float health) {
    this->health = health;
    }

void Enemy::setAttackDamage(float attackDamage) {
    this->attackDamage = attackDamage;
}