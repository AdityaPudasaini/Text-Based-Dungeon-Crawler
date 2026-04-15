#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
    protected:
        float health {};
        float attackDamage {};

    public:
        Enemy();

        Enemy(float health, float attackDamage);

        float getHealth() const;

        float getAttackDamage() const;

        void setHealth(float health);

        void setAttackDamage(float attackDamage);
};

#endif
