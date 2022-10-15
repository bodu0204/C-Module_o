#ifndef FIXED_HPP 
#define FIXED_HPP 

#include <iostream>
#include <cmath> 

class Fixed
{
private:
	unsigned int num;
	unsigned int position;

public:
	int getRawBits(void) const; 
	void setRawBits(int const raw);

	Fixed();
	Fixed(Fixed const &);
	Fixed(int);
	Fixed(float);
	Fixed &operator= (Fixed const&);
	bool operator< (Fixed const&)const;
	bool operator> (Fixed const&)const;
	bool operator<= (Fixed const&)const;
	bool operator>= (Fixed const&)const;
	bool operator== (Fixed const&)const;
	bool operator!= (Fixed const&)const;
	Fixed operator+ (Fixed const&) const;
	Fixed operator- (Fixed const&) const;
	Fixed operator* (Fixed const&) const;
	Fixed operator/ (Fixed const&) const;
	Fixed operator++ (void);
	Fixed operator++ (int);
	Fixed operator-- (void);
	Fixed operator-- (int);
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed const &min(Fixed const&, Fixed const&);
	static Fixed const &max(Fixed const&, Fixed const&);
	static Fixed &min(Fixed &v1, Fixed &v2);
	static Fixed &max(Fixed &v1, Fixed &v2);
	~Fixed();
};
std::ostream &operator<< (std::ostream &os, Fixed F);

#endif