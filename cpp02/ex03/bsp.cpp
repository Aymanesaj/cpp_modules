#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed alpha, beta, denominator, result;

    denominator = ((b.getY() - c.getY()) * (a.getX() - c.getX()))
        + ((c.getX() - b.getX()) * (a.getY() - c.getY()));
    alpha = (((b.getY() - c.getY()) * (point.getX() - c.getX()))
        + ((c.getX() - b.getX()) * (point.getY() - c.getY()))) / denominator;
    beta = (((c.getY() - a.getY()) * (point.getX() - c.getX()))
        + ((a.getX() - c.getX()) * (point.getY() - c.getY()))) / denominator;
    result = Fixed(1) - alpha - beta;
    if ((alpha > 0 && alpha < 1) && (beta > 0 && beta < 1) && (result > 0 && result < 1))
        return (true);
    return (false);
}