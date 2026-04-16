#ifndef FAULT
#define FAULT
#include <iostream>
#include <string>
class Article
{
private:
    std::string name;
    double price;
    int stock;
    std::string category;
    const int id;

public:
    Article(std::string name, double price, int stock, std::string category, const int id);
    bool setPrice(double price);
    bool sell(int amount);
    bool restock(int amount);
    bool applyDiscount(double percent);
    double getPrice() const;
    bool isAvailable() const;
    bool printInfo() const;
};
#endif