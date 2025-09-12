#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(const float x_val, const float y_val);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();
        const Fixed&    getX() const;
        const Fixed&    getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif