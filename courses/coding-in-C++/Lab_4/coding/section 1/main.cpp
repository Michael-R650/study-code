#include <iostream>
#include <cmath>
class Vector2D
{
private:
    double x;
    double y;

public:
    /**
     * @brief Construct a new Vector 2 D object
     *
     */
    Vector2D()
    {
        this->x = 0;
        this->y = 0;
    }
    /**
     * @brief Construct a new Vector 2 D object
     *
     * @param x
     * @param y
     */
    Vector2D(double x, double y) : x(x), y(y) {}
    /**
     * @brief Get the x object
     *
     * @return double
     */
    double get_x()
    {
        return x;
    }
    /**
     * @brief Get the y object
     *
     * @return double
     */
    double get_y()
    {
        return y;
    }
    /**
     * @brief print both attributes
     *
     */
    void print() const
    {
        std::cout << "X" << x << "\n";
        std::cout << "Y" << y << "\n";
    }
    double length() const
    {
        return sqrt((x * x + y * y));
    }
    double length(int precision) const
    {
        double factor = std::pow(10.0, precision);

        return std::round(sqrt((x * x + y * y)) * factor) / factor;
    }

    /**
     * @brief
     *
     * @param v
     * @return Vector2D
     */
    Vector2D &operator+=(const Vector2D &v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }
    friend Vector2D operator+(const Vector2D &, const Vector2D &);
};
// Vector2D operator+(const Vector2D &v, const Vector2D &x)
// {
//     return Vector2D(v.get_x() + x.get_x(),
//                     v.get_y() + x.get_y());
// }

int main()
{
    Vector2D v1(3.3, 4.4);
    v1.print();
    std::cout << v1.length() << "\n";
    std::cout << v1.length(0) << "\n";

    return 0;
    
}
