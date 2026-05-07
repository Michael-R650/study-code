#ifndef PAYLOAD
#define PAYLOAD
template <typename T>
void swap(T &a, T &b)
{
    T u = a;
    a = b;
    b = u;
};
#endif