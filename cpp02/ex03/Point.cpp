#include "Point.hpp"

Point::Point():x(0),y(0) {}

Point::Point(const float x_val, const float y_val):x(x_val),y(y_val) {}

Point::Point(const Point& other):x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other) { 
    (void)other;
    return (*this); }

Point::~Point() {}

const Fixed&    Point::getX() const { return (x); }

const Fixed&    Point::getY() const { return (y); }