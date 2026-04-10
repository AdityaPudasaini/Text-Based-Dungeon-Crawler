#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        float health {};
        float mana {};
        float attackDamage {};

    public:
        Player(float health, float mana, float attackDamage);

        float getHealth() const;

        float getMana() const;

        float getAttackDamage() const;

        void setHealth(float health);

        void setMana(float mana);

        void setAttackDamage(float attackDamage);
};

#endif
