#include <iostream>
#include <string>
constexpr int MAXSLOTS = 10;

class Weapon;
class Character;
class Healer;

class Inventory
{
private:
    unsigned int itemCount;
    std::string items[MAXSLOTS];

public:
    /**
     * @brief Construct a new Inventory object
     *
     */
    Inventory();
    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool isEmpty() const;
    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool isFull() const;
    /**
     * @brief
     *
     * @param item
     * @return true
     * @return false
     */
    bool addItem(std::string &item);
    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool removeLastItem();
};

class Weapon
{
private:
    std::string name;
    int damage;
    Character *owner;

public:
    /**
     * @brief Construct a new Weapon object
     *
     * @param name
     * @param dmg
     */
    Weapon(std::string name, int dmg);
    /**
     * @brief Get the Name object
     *
     * @return std::string
     */
    std::string getName() const;
    /**
     * @brief Get the Dmg object
     *
     * @return int
     */
    int getDmg() const;
};

class Character
{
    friend class Healer;
    int healthPoints;

protected:
    std::string name;
    int level;
    int experiencePoints;
    const int MAXLEVEL = 10;
    int levelLimit[9];
    Inventory *inventory;
    Weapon *weapon;

public:
    Character(std::string name, int level, int exp);
    /**
     * @brief
     *
     * @param dmg
     * @return Character&
     */
    Character &damageTaken(int dmg);
    /**
     * @brief Get the Inventory object
     *
     * @return Inventory
     */
    Inventory getInventory() const;
    /**
     * @brief Get the Level object
     *
     * @return int
     */
    int getLevel() const;
    /**
     * @brief
     *
     */
    void levelUp();
    /**
     * @brief
     *
     * @param exp
     * @return Character&
     */
    Character &earnExperience(int exp);
    /**
     * @brief Get the Health Points object
     *
     * @return int
     */
    int getHealthPoints() const;
};

class Mage : public Character
{
private:
    int magicPoints;

public:
    Mage(std::string name, int level, int exp, int magicPoints);
    Mage &regenerateMagic(int magicPoints);
    void displayStatus() const;
};
class Warrior : public Character
{
private:
    int wsPoint;

public:
    /**
     * @brief Construct a new Warrior object
     *
     * @param name
     * @param level
     * @param exp
     * @param wsPoints
     */
    Warrior(std::string name, int level, int exp, int wsPoints);
    /**
     * @brief
     *
     * @param wsPoint
     * @return Warrior&
     */
    Warrior &regenerateWSPoints(int wsPoint);
    /**
     * @brief
     *
     */
    void displayStatus() const;
};

class Healer
{
public:
    /**
     * @brief
     *
     * @param healthPoints
     * @param target
     * @return Healer&
     */
    Healer &heal(int healthPoints, Character &target);
};

class Thief : public Warrior
{
public:
    /**
     * @brief
     *
     * @param target
     * @return Thief&
     */
    Thief &steal(Character &target);
};