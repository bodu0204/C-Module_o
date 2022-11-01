#ifndef FIXED_HPP 
#define FIXED_HPP 

#include <iostream>
#include <cmath> 

class Fixed
{
private:
	int num;
	const unsigned int position;

public:
	int getRawBits(void) const; 
	void setRawBits(int const raw);

	Fixed();
	Fixed(Fixed const &);
	Fixed(int);
	Fixed(float);
	Fixed &operator= (Fixed const&);
	float toFloat(void) const;
	int toInt(void) const;
	~Fixed();
};
std::ostream &operator<< (std::ostream &os, Fixed const &F);
#endif
