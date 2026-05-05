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
    Vector2D() : x(0.0), y(0.0) {}
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
    double get_x() const
    {
        return x;
    }
    /**
     * @brief Get the y object
     *
     * @return double
     */
    double get_y() const
    {
        return y;
    }
    /**
     * @brief print both attributes
     *
     */
    void print() const
    {
        std::cout << "X " << x << "\n";
        std::cout << "Y " << y << "\n";
    }
    /**
     * @brief 
     * 
     * @return double 
     */
    double length() const
    {
        return sqrt((x * x + y * y));
    }
    /**
     * @brief 
     * 
     * @param precision 
     * @return double 
     */
    double length(int precision) const
    {
        double factor = std::pow(10.0, precision);

        return std::round(sqrt((x * x + y * y)) * factor) / factor;
    }
    /**
     * @brief 
     * 
     * @param another 
     */
    void operator+=(const Vector2D &another)
    {
        x += another.get_x();
        y += another.get_y();
    }
    /**
     * @brief 
     * 
     * @param another 
     * @return true 
     * @return false 
     */
    bool operator==(const Vector2D & another){
        return (x==another.get_x()&&y==another.get_y());

    }
    /**
     * @brief 
     * 
     * @param another 
     * @return true 
     * @return false 
     */
    bool operator!=(const Vector2D & another){
        return (x!=another.get_x()||y!=another.get_y());
    }
};
/**
 * @brief 
 * 
 * @param v 
 * @param x 
 * @return Vector2D 
 */
Vector2D operator+(const Vector2D &v, const Vector2D &x)
{
    return Vector2D(v.get_x() + x.get_x(),
                    v.get_y() + x.get_y());
};


/**
 * @brief 
 * 
 * @param v 
 * @param scalar 
 * @return Vector2D 
 */
Vector2D operator*(const Vector2D &v, double scalar)
{
    return Vector2D(scalar * v.get_x(), scalar * v.get_y());
};



/**
 * @brief 
 * 
 * @param scalar 
 * @param v 
 * @return Vector2D 
 */
Vector2D operator*(double scalar, const Vector2D &v)
{
    return Vector2D(scalar * v.get_x(), scalar * v.get_y());
};
/**
 * @brief 
 * 
 * @param v 
 */
void printVector(const Vector2D & v){
     std::cout << "X " << v.get_x() << "\n";
        std::cout << "Y " << v.get_y() << "\n";
}



int main()
{
    Vector2D v1(3.3, 4.4);
    v1.print();
    std::cout <<"X "<< v1.length() << "\n";
    std::cout <<"Y "<< v1.length(0) << "\n";

    Vector2D v2(3,4);
    Vector2D v3 = v1 + v2;
    v3.print();
    v3 = v3 * 5;
    v3.print();
    std::cout <<std::boolalpha <<"Compare equal: " <<(v1==v2)<<"\n";
    std::cout <<std::boolalpha <<"Compare unequal: " <<(v1!=v2)<<"\n";

    return 0;
}
