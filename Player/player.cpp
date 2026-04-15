#include "Player.h"

Player::Player() {
    health = 100;
    mana = 50;
    attackDamage = 15;
}

Player::Player(float health, float mana, float attackDamage) {
    this->health = health;
    this->mana = mana;
    this->attackDamage = attackDamage;
}

float Player::getHealth() const {
    return health;
}

float Player::getMana() const {
    return mana;
}

float Player::getAttackDamage() const {
    return attackDamage;
}

void Player::setHealth(float health) {
    this->health = health;
}

void Player::setMana(float mana) {
    this->mana = mana;
}

void Player::setAttackDamage(float attackDamage) {
    this->attackDamage = attackDamage;
}
