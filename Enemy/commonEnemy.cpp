#include "commonEnemy.h"

commonEnemy::commonEnemy() {
    setHealth(26);
}

commonEnemy::commonEnemy(float health) {
    this -> health = health;
}

void commonEnemy::resetEnemy() {
    setHealth(26);
}
