#ifndef USER
#define USER
#include <string>
class User
{
protected:
    std::string name;
    int id;

public:
/**
 * @brief Construct a new User object
 * 
 * @param name 
 * @param id 
 */
    User(std::string name, int id);
    /**
     * @brief 
     * 
     */
    void printInfo() const;
};




class Student : protected User
{
private:
    int score;

public:
/**
 * @brief Construct a new Student object
 * 
 * @param name 
 * @param id 
 */
    Student(std::string name, int id, int score) : User(name, id),score(score) {};
    void printRole();
};




class Instructor : protected User
{
private:
    int happiness;

public:
/**
 * @brief Construct a new Instructor object
 * 
 * @param name 
 * @param id 
 */
    Instructor(std::string name, int id, int happiness) : User(name, id),happiness(happiness) {};
    void printRole();
};
#endif