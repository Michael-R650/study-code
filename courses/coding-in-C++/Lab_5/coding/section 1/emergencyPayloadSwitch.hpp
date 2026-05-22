#ifndef PAYLOAD
#define PAYLOAD
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
// #include <numeric>
// #include <cstddef>
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
template <typename S, int size>
void printSensorFrame(S (&a)[size])
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
template <typename T>
T sum(const std::vector<T> &vec)
{
    T sum = T{};

    for (const auto value : vec)
    {
        sum += value;
    }
    return sum;
};
template <typename T>
double analyze(const std::vector<T> &vec)
{
    if (vec.empty())
    {
        std::cout << "vector is empty\n";
        return -1;
    }
    std::cout << std::endl
              << std::setw(10) << "Biggest: " << std::setw(10) << *std::max_element(vec.begin(), vec.end()) << std::endl;
    std::cout << std::setw(10) << "Smallest: " << std::setw(10) << *std::min_element(vec.begin(), vec.end()) << std::endl;
    std::cout << std::setw(10) << "Sum: " << std::setw(10) << sum(vec) << std::endl;
    return 1;
}

template <typename T, int size>
std::vector<T> fixedSize(T (&array)[size], int fixedSize)
{
    std::vector<T> temp;

    for (int i = 0; i <= fixedSize; ++i)
    {
        temp.push_back(array[i]);
        std::cout << i << ", ";
    }

    return temp;
};

template <>
double analyze<bool>(const std::vector<bool> &vec)
{
    if (std::accumulate(vec.begin(), vec.end(), 1) > std::accumulate(vec.begin(), vec.end(), 0)||std::accumulate(vec.begin(), vec.end(), true) > std::accumulate(vec.begin(), vec.end(), false))
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

#endif