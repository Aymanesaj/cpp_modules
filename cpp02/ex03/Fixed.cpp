#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed():value(0)
{
}

Fixed::Fixed( const Fixed& other )
{
    operator=(other);
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other){
        this->setRawBits(other.getRawBits());
    }
    return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
    return (value);
}

void    Fixed::setRawBits( int const raw )
{
    value = raw;
}

Fixed::Fixed(const int n)
{
    setRawBits(n * (1 << fractional_bits));
}

Fixed::Fixed(const float n)
{
    setRawBits(roundf(n * (1 << fractional_bits)));
}

float Fixed::toFloat( void ) const
{
    return (float(getRawBits()) / (1 << fractional_bits));
}

int Fixed::toInt( void ) const
{
    return (getRawBits() / (1 << fractional_bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const
{
    return (getRawBits() > other.getRawBits());
}
bool Fixed::operator<(const Fixed& other) const
{
    return (getRawBits() < other.getRawBits());
}
bool Fixed::operator>=(const Fixed& other) const
{
    return (getRawBits() >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed& other) const
{
    return (getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(const Fixed& other) const
{
    return (getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed New;
    New.setRawBits(getRawBits() + other.getRawBits());
    return (New);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed New;
    New.setRawBits(getRawBits() - other.getRawBits());
    return (New);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed New;
    New.setRawBits((getRawBits() * other.getRawBits()) >> fractional_bits);
    return (New);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed New;
    New.setRawBits((getRawBits() << fractional_bits) / other.getRawBits());
    return (New);
}

Fixed& Fixed::operator++()
{
    setRawBits(getRawBits() + 1);
    return (*this);
}

Fixed& Fixed::operator--()
{
    setRawBits(getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed   old(*this);
    setRawBits(getRawBits() + 1);
    return (old);
}

Fixed Fixed::operator--(int)
{
    Fixed   old(*this);
    setRawBits(getRawBits() - 1);
    return (old);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}
