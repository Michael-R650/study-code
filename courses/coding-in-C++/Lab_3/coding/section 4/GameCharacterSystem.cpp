#include <iostream>
#include <string>
#include "GameCharacterSystem.hpp"
Inventory::Inventory() : itemCount(0)
{
}
bool Inventory::isEmpty() const
{
    return !itemCount;
}
bool Inventory::isFull() const
{
    return itemCount >= MAXSLOTS;
}
bool Inventory::addItem(std::string &newItem)
{
    if (isFull())
    {
        return false;
    }
    else
    {
        items[itemCount] = newItem;
        itemCount++;
        return true;
    }
}
bool Inventory::removeLastItem()
{
    if (!isEmpty())
    {
        items[itemCount] = nullptr;
        return true;
    }
    else
    {
        return false;
    }
}
Weapon::Weapon(std::string name, int damage, Character *owner): name(name), damage(damage),owner(owner){

}
std::string Weapon::getName() const
{
    return name;
}
int Weapon::getDmg() const
{
    return damage;
}
Character::Character(std::string name, int level, int exp) : name(name), level(level), experiencePoints(exp), healthPoints(100)
{

    inventory = new Inventory();
    weapon = nullptr;
}
Character &Character::setWeapon(Weapon &weapon){
this->weapon = &weapon;
return *this;
}
Character &Character::damageTaken(int dmg)
{
    if ((healthPoints - dmg) > 0)
    {
        healthPoints -= dmg;
    }
    else
    {
        healthPoints = 0;
        std::cout << "tot\n";
    }
    return *this;
}
Inventory Character::getInventory() const
{
    return *inventory;
}
int Character::getLevel() const
{
    return level;
}
void Character::levelUp()
{
    if (level < MAXLEVEL)
    {
        level += 1;
    }
}
Character &Character::earnExperience(int exp)
{
    experiencePoints = experiencePoints + exp;

    if (experiencePoints > (level * 100))
    {
        experiencePoints = experiencePoints - (level * 100);
        levelUp();
    }
    return *this;
}
int Character::getHealthPoints() const
{
    return healthPoints;
}
Mage::Mage(std::string name, int level, int exp, int magicPoints) : Character(name, level, exp), magicPoints(magicPoints)
{
}
Mage &Mage::regenerateMagic(int magicpts)
{
    magicPoints += magicpts;
    return *this;
}
void Mage::displayStatus() const
{
    std::cout << "------------------------" << "\n";
    std::cout << "Level:" << level << "\n";
    std::cout << "Mana:" << magicPoints << "\n";
    std::cout << "Name:" << name << "\n";
    std::cout << "EXP:" << experiencePoints << "\n";
    std::cout << "Leben: " << getHealthPoints() << "\n";
    if (weapon != nullptr)
    {

        std::cout << "Weapon: " << weapon->getName() << "\n";
        std::cout << "Weapondmg: " << weapon->getDmg() << "\n";
    }
    std::cout << "------------------------" << "\n";
}
Warrior::Warrior(std::string name, int level, int exp, int wsPoints) : Character(name, level, exp), wsPoint(wsPoints)
{
}
Warrior &Warrior::regenerateWSPoints(int wspoint)
{
    wsPoint += wspoint;
    return *this;
}
void Warrior::displayStatus() const
{
    std::cout << "------------------------" << "\n";
    std::cout << "Level:" << level << "\n";
    std::cout << "wsPoint:" << wsPoint << "\n";
    std::cout << "Name:" << name << "\n";
    std::cout << "EXP:" << experiencePoints << "\n";
    std::cout << "Leben: " << getHealthPoints() << "\n";
    if (weapon != nullptr)
    {
        std::cout << "Weapon: " << weapon->getName() << "\n";
        std::cout << "Weapondmg: " << weapon->getDmg() << "\n";
    }
    std::cout << "------------------------" << "\n";
}

Healer &Healer::heal(int hp, Character &target)
{
    target.healthPoints += hp;
    return *this;
}
Thief::Thief(std::string name, int level, int exp,int wsPoint):Warrior(name, level, exp,wsPoint){

}
Thief &Thief::steal(Character &target)
{
    target.getInventory().removeLastItem();
    return *this;
}