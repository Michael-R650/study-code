#include "DrinkBuilder.hpp"
#include <iostream>
#include <string>
#include <cstdint>
/**
 * @brief 
 * 
 * @param par_name 
 * @return Drink& 
 */
Drink &Drink::setName(const std::string &par_name)
{
    this->name = par_name;
    return *this;
}
/**
 * @brief 
 * 
 * @param par_sugar 
 * @return Drink& 
 */
Drink &Drink::setSugar(std::uint16_t par_sugar)
{
    this->sugar = par_sugar;
    return *this;
}
/**
 * @brief 
 * 
 * @param par_temp 
 * @return Drink& 
 */
Drink &Drink::setTemperature(std::uint16_t par_temp)
{
    this->temperature = par_temp;
    return *this;
}
/**
 * @brief 
 * 
 * @param par_withMilk 
 * @return Drink& 
 */
Drink &Drink::setWithMilk(bool par_withMilk)
{
    this->withMilk = par_withMilk;
    return *this;
}
/**
 * @brief 
 * 
 * @param par_alc 
 * @return Drink& 
 */
Drink &Drink::setAlcohol(std::uint16_t par_alc)
{
    this->alcohol = par_alc;
    return *this;
}
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Drink::isValid() const
{
    if (name.empty())
    {
        return false;
    };
    if (sugar < MIN_PERCENTAGE || sugar > MAX_PERCENTAGE)
    {
        return false;
    }
    if (temperature < MIN_TEMPERATURE || temperature > MAX_TEMPERATURE)
    {
        return false;
    }
    if (alcohol < MIN_PERCENTAGE || alcohol > MAX_PERCENTAGE)
    {
        return false;
    }
    return true;
}
/**
 * @brief 
 * 
 */
void Drink::print() const
{
    if (Drink::isValid())
    {
        std::cout << std::boolalpha;
        std::cout << "Drink: " << this->name<<std::endl;
        std::cout << "Sugar: " << this->sugar<<std::endl;
        std::cout << "Temperature: " << this->temperature<<std::endl;
        std::cout << "Alcohol: " << this->alcohol<<std::endl;
        std::cout << "With milk: " << this->withMilk <<std::endl;
    }
    else
    {
        std::cout << "Drink is not Valid";
    }

}
