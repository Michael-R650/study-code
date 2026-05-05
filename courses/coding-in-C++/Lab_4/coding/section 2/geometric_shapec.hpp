#ifndef SHAPE
#define SHAPE

constexpr double PI = 3.14;
class shape
{
public:
    // Each shape has its own furmula for the are of it
    virtual double area() const = 0;
    virtual ~shape();
};
class circle : public shape
{
private:
    double radius;

public:
    circle(double radius);
    double area() const override;
};
class rectangle : public shape
{
private:
    double length;
    double width;

public:
    rectangle(double length, double width);
    double area()const override;
};
#endif