// no header its cpp file
#include <iostream>
#include <string>
#include <iomanip>
#include "fault.hpp"
int main()
{
    Article article1("Laptop", 999.99, 15, "Electronics", 101);

    article1.sell(15);
    article1.restock(5);
    article1.applyDiscount(150);
    if (article1.isAvailable())
    {
        std::cout << "Article available" << std::endl;
    }
    article1.printInfo();

    return 0;
}