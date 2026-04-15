#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <string>

#include "../Enemy/commonEnemy.h"
#include "../Player/player.h"

class Gameplay {
    private:
        Player player;
        commonEnemy enemy;
        std::string playerDecision;
        std::string attackName;
        std::string potionName;
        std::string attackType;
        
        public:
            Gameplay();

            Gameplay(Player player, commonEnemy enemy);

            std::string getPlayerDecision() const;

            std::string getAttackName() const;

            std::string getPotionName() const;

            std::string getAttackType() const;

            void setPlayerDecision(std::string playerDecision);

            void setAttackName(std::string attackName);

            void setPotionName(std::string potionName);

            void setAttackType(std::string attackType);

            void attackTypeSelection();

            void playerAttack();

            void playerUsePotion();

            float calculateDamage(float attackDamage);

            void displayHealthStatus() const;

            void decisionToAttackOrUsePotion();

            void newLevel();
};

#endif
