#ifndef PAYLOAD
#define PAYLOAD
#include <string>
template <typename T>
/**
 * @brief sawp a and b
 *  swap of a and b mit typename T
 * @param a
 * @param b
 */
void swap(T &a, T &b)
{
    T u = a;
    a = b;
    b = u;
};
template <typename S>
void printSensorFrame(S a[], int size)
{
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << a[i] << ", ";
    }
    std::cout << "]\n";
}

template <typename S>
S smallestValue(S a[], int size);

template <>
int smallestValue<int>(int a[], int size)
{
    int temp = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] < temp)
        {
            temp = a[i];
        }
    }
    return temp;
}

template <>
double smallestValue<double>(double a[], int size)
{
    double temp = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] < temp)
        {
            temp = a[i];
        }
    }
    return temp;
}

template <typename T, typename S>
void printLabeled(std::string label1, T value1, std::string label2, S value2)
{
    std::cout << label1 << ": " << value1 << " | " << label2 << ": " << value2 << "\n";
}

#endif