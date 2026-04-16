#include <iostream>

#include "Gameplay/gameplay.h"

int main() {
    Gameplay gameplay;

    while (gameplay.getIsPlayerAlive()) {
        gameplay.decisionToAttackOrUsePotion();
    }
    return 0;
}
