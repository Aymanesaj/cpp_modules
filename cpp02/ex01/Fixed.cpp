#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed():value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other )
{
    std::cout << "Copy constructor called" << std::endl;
    operator=(other);
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other){
        this->setRawBits(other.getRawBits());
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
{
    setRawBits(roundf(n * (1 << fractional_bits)));
    std::cout << "Float constructor called" << std::endl;
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
