#include <iostream>
#include <string>
#include "DrinkBuilder.hpp"

int main(){
    Drink beer;
    beer.setAlcohol(8).setName("beer").setSugar(3).setTemperature(10).print();
    return 0;
}
