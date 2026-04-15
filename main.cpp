#include <iostream>

#include "Gameplay/gameplay.h"

int main() {
    Player player;
    Gameplay gameplay;
    while (player.getHealth() > 0) {
        gameplay.decisionToAttackOrUsePotion();
    }
    return 0;
}
