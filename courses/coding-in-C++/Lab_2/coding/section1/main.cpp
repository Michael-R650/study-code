#include <iostream>
#include "section1.hpp"
int main(){
    std::cout<<"Start"<<std::endl;
    BankAccount kek;
    kek.deposit(100);
    kek.setOwner("Michi");
    kek.getAccoutInfo();
    kek.withdraw(101);
    kek.getAccoutInfo();
    kek.withdraw(10);
    kek.getAccoutInfo();
    std::cout<<"End";
}