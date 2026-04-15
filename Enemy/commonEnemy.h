#ifndef COMMONENEMY_H
#define COMMONENEMY_H

#include "enemy.h"

class commonEnemy : public Enemy {
        
    public:
        commonEnemy();

        commonEnemy(float health);

        void resetEnemy();
};

#endif
