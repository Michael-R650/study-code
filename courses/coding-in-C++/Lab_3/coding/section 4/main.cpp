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
    Healer h1;
    h1.heal(1000,w1);
    w1.displayStatus();
    w1.getInventory();
    
    Weapon weap1("Schwert",10,&w1);
w1.setWeapon(weap1);
w1.displayStatus();
Thief thief1("Tap",4,200,100);
thief1.steal(w1);
w1.displayStatus();
m1.getInventory().addItem("shield");
m1.displayStatus();
    return 0;
}