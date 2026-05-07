#include <iostream>
#include "emergencyPayloadSwitch.hpp"
int main()
{
    int i = 10;
    int j = 9;
    std::string val1 = "Hi";
    std::string val2 = "Tschau";
    double i1 = 1.3;
    double j1 = 5;

    //Sawp funktionen
    std::cout << i << " " << j << "\n";
    swap(i, j);
    std::cout << i << " " << j << "\n";
    std::cout << val1 << " " << val2 << "\n";
    swap(val1, val2);
    std::cout << val1 << " " << val2 << "\n";
    std::cout << i1 << " " << j1 << "\n";
    swap(i1, j1);
    std::cout << i1 << " " << j1 << "\n";
    return 0;
};