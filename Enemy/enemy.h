#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
    private:
        float health {};
        float attackDamage {};
        bool isDefeated {false};

    public:
        Enemy(float health, float attackDamage);

        float getHealth() const;

        float getAttackDamage() const;

        bool getIsDefeated() const;

        void setHealth(float health);

        void setAttackDamage(float attackDamage);

        void setIsDefeated(bool isDefeated);
};

#endif
