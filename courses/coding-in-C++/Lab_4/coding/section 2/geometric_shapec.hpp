#ifndef SHAPE
#define SHAPE

constexpr double PI = 3.14;
class shape
{
public:
    // Each shape has its own furmula for the area
    /**
     * @brief
     *
     * @return double
     */
    virtual double area() const = 0;
    /**
     * @brief Destroy the shape object
     *
     */
    virtual ~shape();
};
class circle : public shape
{
private:
    double radius;

public:
    /**
     * @brief Construct a new circle object
     *
     * @param radius
     */
    circle(double radius);
    /**
     * @brief
     *
     * @return double
     */
    double area() const override;
};
class rectangle : public shape
{
private:
    double length;
    double width;

public:
    /**
     * @brief Construct a new rectangle object
     *
     * @param length
     * @param width
     */
    rectangle(double length, double width);
    /**
     * @brief
     *
     * @return double
     */
    double area() const override;
};
#endif