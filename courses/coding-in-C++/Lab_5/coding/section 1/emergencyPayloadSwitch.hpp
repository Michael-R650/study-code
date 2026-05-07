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
#endif