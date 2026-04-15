#ifndef BOSSENEMY_H
#define BOSSENEMY_H

#include "enemy.h"

class bossEnemy : public Enemy {
    public:
        bossEnemy();

        bossEnemy(float health);
};

#endif