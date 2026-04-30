#include <iostream>
#include "User.hpp"
User::User(std::string name, int id) : name(name), id(id)
{
}
void User::printInfo() const
{
    std::cout << this->name;
    std::cout << this->id;
}
void Student::printRole()
{
    std::cout <<"--------------------\n";
    std::cout << this->name << "\n";
    std::cout << id << "\n";
    std::cout << score << "\n";
    std::cout <<"--------------------\n";
}
void Instructor::printRole()
{
    std::cout <<"--------------------\n";
    std::cout << this->name << "\n";
    std::cout << id << "\n";
    std::cout << happiness << "\n";
    std::cout <<"--------------------\n";
}