#include <string>
#include <iostream>

class BankAccount{
private:
std::string owner;
double balance;
public:
bool setOwner(std::string par_owner);
std::string getOwner();
bool deposit(double);
bool withdraw(double);
bool getBalance();
bool getAccoutInfo();
};
/**
 * @brief 
 * setOwner var
 * @param par_owner 
 * @return true 
 * @return false 
 */
bool BankAccount::setOwner(std::string par_owner){
owner = par_owner;
return true; 
}
/**
 * @brief 
 * return owner name
 * @return std::string 
 */
std::string BankAccount::getOwner(){
    return owner;
}
/**
 * @brief 
 * puts money into bank account
 * @param par_amount 
 * @return true 
 * @return false 
 */
bool BankAccount::deposit(double par_amount){
    balance += par_amount;
    return true;
}
/**
 * @brief 
 * withdraws money from bank account if it wouldnt go into depts
 * @param par_amount 
 * @return true 
 * @return false 
 */
bool BankAccount::withdraw(double par_amount){
    if(balance-par_amount>=0){
        balance=-par_amount;
        return true;
    }
    return false;
}
/**
 * @brief 
 * returns balance of bank account
 * @return true 
 * @return false 
 */
bool BankAccount::getBalance(){
    std::cout<<"Your bankaccount holds: "<<balance<<"Dollar"<<std::endl;
    return true;
}
/**
 * @brief 
 * returns bank information of owner and balance
 * @return true 
 * @return false 
 */
bool BankAccount::getAccoutInfo(){
    std::cout <<"The bankaccountowners name is "<<owner<<std::endl;
    //std::cout<<"Your bankaccount holds: "<<balance<<"Dollar"<<std::endl;
    getBalance();
    return true;
}