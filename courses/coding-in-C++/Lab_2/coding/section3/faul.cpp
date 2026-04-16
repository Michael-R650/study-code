#include <iostream>
#include <string>
#include <iomanip>
#include"fault.hpp"
Article(std::string name, double price, int stock, std::string category, const int id) : nam(name), price : (price), stock : (stock), category : (category)
{
    this->name = name;
};

bool setPrice(double price)
{
    this->price = price;
};

bool sell(int amount)
{
    if((stock-amount)<0){

    }
    stock = stock - amount; // where does stock come from? // no negative logic
}

bool restock(int amount)
{ // no negative parameter number logic
    this->stock += amount;
}

double applyDiscount(double percent)
{ // no double value necessary, no logic for negative and numbers over 100
    price = price - price * percent / 100;
    return price; // same here
}

double getPrice()
{ // const is missing
    return price;
}

bool isAvailable()
{ // const
    if (stock > 0)
        return true;
    else
        return false;
}

bool printInfo()
{ // const
    std::cout << "Article: " << name << endl;
    std::cout << "Category: " << *category << endl;
    std::cout << "Price: " << price << endl;
    std::cout << "Stock: " << stock << endl;
    std::cout << "ID: " << id << endl;
}
}
;
