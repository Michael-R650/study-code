#include<iostream>
#include "geometric_shapec.hpp"

int main(){
    circle c1(3);
    rectangle r1(2,4);
    std::cout << c1.area()<< "\n";
    std::cout << r1.area()<< "\n";
    shape* arr[4];
    arr[0]= new circle(3);
    arr[1]= new circle(4);
    arr[2]= new rectangle(3,4);
    arr[3]= new rectangle(5,6);
    
    for(shape* x: arr){
        std::cout << x->area()<<"\n";
    }
    return 0;
}