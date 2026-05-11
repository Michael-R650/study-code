#include "geometric_shapec.hpp"
/**
 * @brief Destroy the shape::shape object
 * 
 */
shape::~shape() {

};
/**
 * @brief Construct a new circle::circle object
 * 
 * @param radius 
 */
circle::circle(double radius) : radius(radius) {}
/**
 * @brief 
 * 
 * @return double 
 */
double circle::area() const
{
    return (radius * radius * PI);
}
/**
 * @brief Construct a new rectangle::rectangle object
 * 
 * @param length 
 * @param width 
 */
rectangle::rectangle(double length, double width) : length(length), width(width) {}
/**
 * @brief 
 * 
 * @return double 
 */
double rectangle::area() const
{
    return length * width;
}