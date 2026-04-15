#include <iostream>

#include "Gameplay/gameplay.h"

int main() {
    Gameplay gameplay;
    while (gameplay.getIsPlayerAlive() == true) {
        gameplay.decisionToAttackOrUsePotion();
    }
    return 0;
}
