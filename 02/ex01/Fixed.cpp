#include "./Fixed.hpp"

void Fixed::setRawBits(int const raw)
{
	this->num = raw;
}

int Fixed::getRawBits(void) const
{
	return (this->num);
}

Fixed::Fixed(void): position(8)
{
	std::cout << "Default constructor called" << std::endl;
	this->num = 0;
}

Fixed::Fixed(Fixed const &F): position(8)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = F;
}

Fixed::Fixed(int i): position(8)
{
	std::cout << "Int constructor called" << std::endl;
	this->num = i << this->position;
}

Fixed::Fixed(float f): position(8)
{
	std::cout << "Float constructor called" << std::endl;
	this->num = (unsigned int) roundf(f * (1U << this->position));
}

Fixed &Fixed::operator=(Fixed const &F)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = F.getRawBits();
	return (*this);
}

std::ostream &operator<< (std::ostream &os, Fixed const &F)
{
	os << F.toFloat();
	return (os);
}

float Fixed::toFloat(void) const
{
	float f = (float)(this->num);

	f /= 1U << this->position;
	return (f);
}

int Fixed::toInt(void) const
{
	return ((int)(this->num >> this->position));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
