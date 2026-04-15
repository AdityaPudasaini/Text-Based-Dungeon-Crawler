#include "bossEnemy.h"

bossEnemy::bossEnemy() {
    setHealth(75);
}

bossEnemy::bossEnemy(float health) {
    this -> health = health;
}