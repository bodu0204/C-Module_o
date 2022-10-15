#include "Fixed.hpp"

void Fixed::setRawBits(int const raw)
{
	num = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (num);
}

Fixed& Fixed::operator= (Fixed &F)
{
	std::cout << "Copy assignment operator called" << std::endl;
	num = F.getRawBits();
	return (*this);
}

Fixed::Fixed(Fixed &raw): position(8)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = raw;
}

Fixed::Fixed(void): position(8)
{
    (void)position;
	std::cout << "Default constructor called" << std::endl;
	num = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
