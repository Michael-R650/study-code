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
    static constexpr int DEFAULT_TEMP = 15;

public:
    //Drink(const std::string&par_name,int par_sugar, int par_temp,int par_alc, bool par_with_milk);
    Drink &setName(const std::string &par_name);
    Drink &setSugar(std::uint16_t par_sugar);
    Drink &setTemperature(std::uint16_t par_temp);
    Drink &setWithMilk(bool WithMilk);
    Drink &print() const;
    Drink &isValid() const;
};
#endif