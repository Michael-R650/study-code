#include <iostream>
#include <vector>
class Character
{
private:
    std::string name;
    int health;
    int level;
    int exp;
    static constexpr int MIN_LEVEL = 1;
    static constexpr int MAX_LEVEL = 10;
    static constexpr int MAX_HEALTH = 0;

public:
    Character(std::string name, int level = 1) : name(name) {};
    virtual ~Character();
    std::string getName() const;
    int getLevel() const;
    int getHealth() const;
    void addExp(int amount);
    void levelUp();
    Inventory &getInventory();
    Weapon *getWeapon() const;
    void setWeapon(Weapon *weapon);
    virtual void regenerate() const = 0;
    virtual void printStatus() const = 0;

protected:
    void changeHealth(int health);
    friend class Healer;
};
class Inventory
{
private:
    std::vector items;
    std::size_t maxSlots;

public:
    Inventory(std::size_t maxSlots = 10);
    bool isEmpty() const;
    bool isFull() const;
    bool addItem(std::string &item);
    bool removeLastItem(std::string &item);
    std::size_t getCount() const;
    std::size_t getMaxSlots() const;
};
class Weapon
{
private:
    std::string name;
    int damage;

public:
    Weapon(std::string name, int damage);
    std::string getName() const;
    int getDamage() const;
};
class Warrior : public Character
{

private:
    int weaponSkill;

public:
    Warrior(std::string name, int level = 1, int skill = 0);
    void regenerate();
    void printStatus() const;
    int getWeapon() const;
};
class Thief : public Warrior
{
public:
    Thief(std::string name, int level = 1, int skill = 0);
    Thief &steal(Character target);
    void regenerate();
    void printStatus() const;
};
class Mage
{
private:
    int mana;

public:
    Mage(std::string name, int level, int skill = 0);
    void regenerate();
    void printStatus() const;
    int getMana() const;
};
class Healer : public Mage
{
    Healer(std::string name, int level = 1, int mana = 0);
    Healer &heal(Character target);
    void regenerate();
    void printStatus() const;
};