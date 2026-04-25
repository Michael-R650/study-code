#include <iostream>
#include <string>
#include "DrinkBuilder.hpp"

int main(){
    Drink beer;
    beer.setAlcohol(8);
    beer.setName("beer");
    beer.setSugar(3);
    beer.setTemperature(10);
    beer.print();
    return 0;
}
