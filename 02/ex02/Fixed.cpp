#include "./Fixed.hpp"

void Fixed::setRawBits(int const raw)
{
	this->num = raw;
}

int Fixed::getRawBits(void) const
{
	return (this->num);
}

Fixed::Fixed(void): position(8){
	this->num = 0;
}

Fixed::Fixed(Fixed const &F): position(8)
{
	this->num = F.getRawBits();
}

Fixed::Fixed(int i): position(8)
{
	this->num = i << this->position;
}

Fixed::Fixed(float f): position(8)
{
	this->num = (unsigned int) roundf(f * (1U << this->position));
}

Fixed &Fixed::operator=(Fixed const &F){
	this->num = F.getRawBits();
	return (*this);
}

bool  Fixed::operator< (Fixed const& F) const{
	return (this->getRawBits() < F.getRawBits());
}

bool  Fixed::operator> (Fixed const& F) const{
	return (this->getRawBits() > F.getRawBits());
}

bool  Fixed::operator<= (Fixed const& F) const{
	return (this->getRawBits() <= F.getRawBits());
}

bool  Fixed::operator>= (Fixed const& F) const{
	return (this->getRawBits() > F.getRawBits());
}

bool  Fixed::operator== (Fixed const& F) const{
	return (this->getRawBits() == F.getRawBits());
}

bool  Fixed::operator!= (Fixed const& F) const{
	return (this->getRawBits() != F.getRawBits());
}

Fixed Fixed::operator+ (Fixed const& F) const{
	return (Fixed((float)(this->getRawBits() + F.getRawBits()) / (1U << this->position)));
}

Fixed Fixed::operator- (Fixed const& F) const{
	return (Fixed((float)(this->getRawBits() - F.getRawBits()) / (1U << this->position)));
}

Fixed Fixed::operator* (Fixed const& F) const{
	return (Fixed((float)(this->getRawBits() * F.getRawBits()) / (1U << (this->position * 2))));
}

Fixed Fixed::operator/ (Fixed const& F) const{
	return (Fixed((float)this->getRawBits() / F.getRawBits()));
}

Fixed Fixed::operator++ (void){
	this->num++;
	return (*this);
}

Fixed Fixed::operator++ (int){
	Fixed cpy(*this);
	this->num++;
	return (cpy);
}

Fixed Fixed::operator-- (void){
	this->num--;
	return (*this);
}

Fixed Fixed::operator-- (int){
	Fixed cpy(*this);
	this->num--;
	return (cpy);
}

std::ostream &operator<< (std::ostream &os, Fixed const F)
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

Fixed const &Fixed::max(Fixed const& v1, Fixed const& v2)
{
	if (v1 > v2)
		return(v1);
	return (v2);
}

Fixed &Fixed::max(Fixed &v1, Fixed &v2)
{
	if (v1 > v2)
		return(v1);
	return (v2);
}

Fixed const &Fixed::min(Fixed const& v1, Fixed const& v2)
{
	if (v1 < v2)
		return(v1);
	return (v2);
}

Fixed &Fixed::min(Fixed &v1, Fixed &v2)
{
	if (v1 < v2)
		return(v1);
	return (v2);
}

Fixed::~Fixed(void){}
