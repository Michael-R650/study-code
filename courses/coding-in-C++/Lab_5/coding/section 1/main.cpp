#include <iostream>
#include "emergencyPayloadSwitch.hpp"
// temps are better because i dont have to wrtie the code for each datatype again
int main()
{
    //section 1
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
    

    //section 2
    int arrayOne[]={1,2,3,4,5,6,7,8,9,0};
    double arrayTwo[]={1.2,2.2,3.3,4.4,5.5};
    char arrayThree[]={'a','b','c','d','e','f','g'};
    printSensorFrame(arrayOne,sizeof(arrayOne)/sizeof(int));
    printSensorFrame(arrayTwo,sizeof(arrayTwo)/sizeof(double));
    printSensorFrame(arrayThree,sizeof(arrayThree)/sizeof(char));
std::cout<<smallestValue(arrayOne,sizeof(arrayOne)/sizeof(int))<<"\n";
std::cout<<smallestValue(arrayTwo,sizeof(arrayTwo)/sizeof(double))<<"\n";
return 0;
};