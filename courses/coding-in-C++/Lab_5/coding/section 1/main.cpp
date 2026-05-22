#include <iostream>
#include "emergencyPayloadSwitch.hpp"
#include <vector>
#include <algorithm>
// temps are better because i dont have to wrtie the code for each datatype again
int main()
{
    // task 1
    int i = 10;
    int j = 9;
    std::string val1 = "Hi";
    std::string val2 = "Tschau";
    double i1 = 1.3;
    double j1 = 5;

    // task 2
    std::cout << i << " " << j << "\n";
    swap(i, j);
    std::cout << i << " " << j << "\n";
    std::cout << val1 << " " << val2 << "\n";
    swap(val1, val2);
    std::cout << val1 << " " << val2 << "\n";
    std::cout << i1 << " " << j1 << "\n";
    swap(i1, j1);
    std::cout << i1 << " " << j1 << "\n";

    // task 3
    int arrayOne[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    double arrayTwo[] = {1.2, 2.2, 3.3, 4.4, 5.5};
    char arrayThree[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

    printSensorFrame(arrayOne);
    printSensorFrame(arrayTwo);
    printSensorFrame(arrayThree);
    // task 4
    std::cout << smallestValue(arrayOne, sizeof(arrayOne) / sizeof(int)) << "\n";
    std::cout << smallestValue(arrayTwo, sizeof(arrayTwo) / sizeof(double)) << "\n";
    // task 5
    printLabeled("Label1", 10, "Label 2", 4.6);

    // SECTION 2
    // task 6
    std::vector<int> vec1 = {42, 17, 42, 5, 99, 17, 63, 12};
    std::cout << '[';
    for (int x : vec1)
    {
        std::cout << x << ' ';
    }
    std::cout << ']';
    std::sort(vec1.begin(), vec1.end());
    std::cout << '[';
    for (int x : vec1)
    {
        std::cout << x << ' ';
    }
    std::cout << ']';
    std::vector<int>::iterator it;
    it = std::find(vec1.begin(), vec1.end(), 63);
    if (it != vec1.end())
    {
        std::cout << *it << '\n';
    }
    else
    {
        std::cout << "Object not found";
    }

    // task 7
    std::vector<int> vec2 = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    std::cout << '[';
    for (int x : vec2)
    {
        std::cout << x << ' ';
    }
    std::cout << ']';
    std::replace(vec2.begin(), vec2.end(), -1, 0);
    std::cout << '[';
    for (int x : vec2)
    {
        std::cout << x << ' ';
    }
    std::cout << ']';
    std::vector<int>::iterator it2;
    vec2.resize(8);
    std::cout << '[';
    for (int x : vec2)
    {
        std::cout << x << ' ';
    }
    std::cout << ']';

    std::reverse(vec2.begin(), vec2.end());
    std::cout << '[';
    for (int x : vec2)
    {
        std::cout << x << ' ';
    }
    std::cout << ']';
    // task 8
    std::vector<int>::iterator it3;
    std::cout << '[';
    for (std::vector<int>::iterator it3 = vec2.begin(); it3 != vec2.end(); ++it3)
    {
        std::cout << *it3 << ' ';
    }
    std::cout << ']';

    //task 9

    std::vector<int> vec3{0,5,3,2,9};
analyze(vec3);
std::vector par = fixedSize(arrayOne,5);
analyze(par);

std::vector<bool> vec4{1,1,0,0,1,1,0};
if(analyze(vec4)){
    std::cout<<"True";
}else{
    std::cout<<"False";
};
std::vector<bool> vec5{true,true,false,false,true};
if(analyze(vec5)){
    std::cout<<"True";
}else{
    std::cout<<"False";
};
    return 0;
};