#include "geometric_shapec.hpp"
shape::~shape() {

};
circle::circle(double radius) : radius(radius) {}
double circle::area() const
{
    return (radius * radius * PI);
}
rectangle::rectangle(double length, double width) : length(length), width(width) {}
double rectangle::area() const
{
    return length * width;
}