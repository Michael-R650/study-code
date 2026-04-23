#include <iostream>
#include <cstdint>
#include <limits>
namespace validation
{
    const std::uint16_t ADULT_LIMIT = 18;
    const std::uint16_t SENIOR_LIMIT = 65;
/**
 * @brief 
 * 
 * @param age 
 * @return true 
 * @return false 
 */
    bool isAdult(std::uint8_t age)
    {
        return (age >= ADULT_LIMIT);
    }
    /**
     * @brief 
     * 
     * @param age 
     * @return true 
     * @return false 
     */
    bool isSenior(std::uint8_t age)
    {
        return (age >= SENIOR_LIMIT);
    }
}

int main()
{
    int temp = 0;
    std::uint8_t alter = 0;

    while (true)
    {
        if (!(std::cin >> temp))
        {
            std::cout << "Please insert your age:";
            std::cout << std::endl;

            std::cout << "Invalid input.Please try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (temp < 0)
        {
            std::cout << "Number cant be negative" << std::endl;
            continue;
        }
        if (temp > 130)
        {
            std::cout << "Number is unrealistically high" << std::endl;
            continue;
        }
        break;
    }

    alter = static_cast<std::uint8_t>(temp);
    std::cout << "You are " << alter << " years old." << std::endl;
    if (validation::isSenior(alter))
    {
        std::cout << "That means that you are a senior citizen" << std::endl;
    }
    else if (validation::isAdult(alter))
    {
        std::cout << "That means that you are an adult" << std::endl;
    }
    else
    {
        std::cout << "That means that you are still a kid or teenager";
    }
}
