#ifndef DRINKBUILDER
#define DRINKBUILDER
#include <string>
#include <cstdint>
class Drink
{
private:
    std::string name;
    int sugar;
    int temperature;
    int alcohol;
    bool withMilk;
    static constexpr std::uint16_t MIN_PERCENTAGE = 0;
    static constexpr std::uint16_t MAX_PERCENTAGE = 100;
    static constexpr std::int16_t MIN_TEMPERATURE = -20;
    static constexpr std::uint16_t MAX_TEMPERATURE = 150;

public:
    Drink &setName(const std::string &par_name);
    Drink &setSugar(std::uint16_t par_sugar);
    Drink &setTemperature(std::uint16_t par_temp);
    Drink &setWithMilk(bool par_withMilk);
    Drink &setAlcohol(std::uint16_t par_alc);
    void print() const;
    bool isValid() const;
};
#endif