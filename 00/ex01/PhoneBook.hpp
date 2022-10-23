#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
private:
    Contact c[MAX_CONTACTS];
    size_t s;
    size_t l;
    size_t idx(size_t);
    void print_ten(std::string);
public:
    PhoneBook(){s = 0LU;l = 0LU;}
    ~PhoneBook(){}
    void add(void);
    void search(void);
};
#endif