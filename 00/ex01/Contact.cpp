#include <string>
#include <ctype.h>
#include <iostream>
#include "Contact.hpp"

int Contact::set_first_name(std::string fname)
{
	if (!fname.length())
		return 1;
	first_name = fname;
	return 0;
}
int Contact::set_last_name(std::string lname)
{
	if (!lname.length())
		return 1;
	last_name = lname;
	return 0;
}
int Contact::set_nickname(std::string nname)
{
	if (!nname.length())
		return 1;
	nickname = nname;
	return 0;
}
int Contact::set_phone_number(std::string pnumber)
{
	if (!pnumber.length())
		return 1;
	for (size_t i = 0; i < pnumber.length(); i++)
	{
		if (!isdigit(pnumber.c_str()[i]))
			return 1;
	}
	phone_number = pnumber;
	return 0;
}
int Contact::set_darkest_secret(std::string dsecret)
{
	if (!dsecret.length())
		return 1;
	darkest_secret = dsecret;
	return 0;
}
std::string Contact::get_first_name(){return first_name;}
std::string Contact::get_last_name(){return last_name;}
std::string Contact::get_nickname(){return nickname;}
std::string Contact::get_phone_number(){return phone_number;}
std::string Contact::get_darkest_secret(){return darkest_secret;}
