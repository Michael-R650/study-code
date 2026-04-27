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

Student::Student(){

}
void Student::printInfo(){

}