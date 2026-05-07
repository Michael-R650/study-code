#ifndef PAYLOAD
#define PAYLOAD
#include <string>
#include <iostream>
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
}
/**
 * @brief prints out the array
 *
 * @tparam S
 * @param a
 * @param size
 */
template <typename S>
void printSensorFrame(S a[], int size)
{
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << a[i] << (i < size - 1 ? ", " : "");
    }
    std::cout << "]\n";
}

template <typename S>

S smallestValue(S a[], int size);
/**
 * @brief  returns the smallest value from the array if it is an int
 *
 * @tparam S
 * @param a
 * @param size
 * @return S
 */
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
/**
 * @brief returns the smallest value from the array if it is a double
 *
 * @tparam
 * @param a
 * @param size
 * @return int
 */
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
/**
 * @brief prints out the labeled version
 *
 * @tparam T
 * @tparam S
 * @param label1
 * @param value1
 * @param label2
 * @param value2
 */
template <typename T, typename S>
void printLabeled(std::string label1, T value1, std::string label2, S value2)
{
    std::cout << label1 << ": " << value1 << " | " << label2 << ": " << value2 << "\n";
}

#endif