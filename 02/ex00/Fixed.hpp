#ifndef FIXED_HPP 
#define FIXED_HPP 

#include <iostream>

class Fixed
{
private:
int num;
const unsigned int position;
public:
	int getRawBits(void) const; 
	void setRawBits(int const raw);

	Fixed();
	Fixed(Fixed&);
	Fixed& operator = (Fixed&);
	~Fixed();
};

#endif