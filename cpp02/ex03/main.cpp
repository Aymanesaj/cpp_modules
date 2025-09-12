#include "Point.hpp"

int main()
{
    Point A(0, 0), B(10, 0), C(5, 10), Point(0, 0);

    if (bsp(A, B, C, Point))
        std::cout << "The point is inside the triangle." << std::endl;
    else
        std::cout << "The point is outside the triangle." << std::endl;
}