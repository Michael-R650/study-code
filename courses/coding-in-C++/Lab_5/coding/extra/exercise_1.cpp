#include <iostream>
template <typename T, typename Z>
class Pair
{
private:
    T value1;
    Z value2;

public:
    Pair() {

    };
    Pair(T value1, Z value2) : value1(value1), value2(value2) {}
    T getvalue1() { return value1; }
    Z getValue2() { return value2; }
    void setvalue1(T value) { this->value1 = value; }
    void setvalue2(Z value) { this->value2 = value; }
    
    void printValue()
    {
        std::cout << "Value1: " << value1 << "\n";
        std::cout << "Value2: " << value2 << "\n";
    }
};
int main()
{
    Pair test(432, 4.3);
    test.printValue();
    test.setvalue1(123.325);
    test.printValue();

    Pair<std::string, int> test2;
    test2.setvalue1("Wert 1");
    test2.setvalue2(43);
    test2.printValue();
    return 0;
}