// no header its cpp file
#include <iostream>
#include <string>
#include <iomanip>
using namespace std; // not a mistake but not the clean version

class Article
{
public: // should be private
    string name;
    double price;
    int stock;
    string *category; // why pointer? // why no enum calss for a list of categories?
    int id;           // should be const
                      // methodes can be public
    //  no destroy function avaliable
    Article(string name, double price, int stock, string category, int id)
    {                  // no logic for wrong inputs, list is missing
        name = name;   // no this pointer
        price = price; // no this pointer
        stock = stock; // no this pointer
        this->id = id;
        this->category = new string; // why init of a string? // no free in the code // no rule of 3
        *this->category = category;  // pointer of this pointer?
    }

    void setPrice(double price)
    {
        price = price; // no this pointer
    }

    void sell(int amount)
    {
        stock = stock - amount; // where does stock come from? // no negative logic
    }

    void restock(int amount)
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

    void printInfo()
    { // const
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main()
{
    Article a("Laptop", 999.99, 10, "Electronics", 101); // no logical name for an object

    a.sell(15);           // only 10 avaliable
    a.restock(-5);        // wrong use of restock methode
    a.price = -100;       // wrong
    a.applyDiscount(150); // not logical

    if (a.isAvailable())
        cout << "Article available" << endl; // stylistic error

    a.printInfo();
    // no return main is int
}