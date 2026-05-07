#include <iostream>
#include "emergencyPayloadSwitch.hpp"
int main()
{
    int i = 10;
    int j = 9;
    std::cout << i << " " << j << "\n";
    swap(i, j);
    std::cout << i << " " << j << "\n";
    return 0;
};