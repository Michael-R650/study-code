#ifndef PAYLOAD
#define PAYLOAD
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
    std::cout<<"[";
    for (int i = 0; i < size; i++)
    {
        std::cout << a[i] << ", ";
    }
std::cout<<"]\n";
}

#endif