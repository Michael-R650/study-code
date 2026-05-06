#include <iostream>
#include <string>
#include "GameCharacterSystem.hpp"

int main()
{
    Mage m1("Mike", 1, 65, 100);
    Warrior w1("Wise", 1, 99, 10);
    w1.displayStatus();
    w1.earnExperience(10);
    w1.displayStatus();
    m1.displayStatus();
    w1.damageTaken(100);

    return 0;
}