#include <iostream>
#include "PhoneBook.hpp"

Contact & PhoneBook::operator [](size_t i)
{
    return this->c[(i + s) % MAX_CONTACTS];
}

void PhoneBook::print_ten(std::string s)
{
    if (s.length() <= 10)
        std::cout << s << std::string("          ").substr(0, 10 - s.length());
    else
        std::cout << s.substr(0, 9) << ".";
}


void PhoneBook::add(void)
{
    if (l < MAX_CONTACTS)
        l++;
    else
        s++;
    std::string str;
    do
    {
        std::cout << "input yrour first name:";
        std::cin >> str;
    } while (c[l].set_first_name(str));
    do
    {
        std::cout << "input yrour last name:";
        std::cin >> str;
    } while (c[l].set_last_name(str));
    do
    {
        std::cout << "input yrour nickname:";
        std::cin >> str;
    } while (c[l].set_nickname(str));
    do
    {
        std::cout << "input yrour phone number:";
        std::cin >> str;
    } while (c[l].set_phone_number(str));
    do
    {
        std::cout << "input yrour darkest secret:";
        std::cin >> str;
    } while (c[l].set_darkest_secret(str));
}

void PhoneBook::search(void)
{
    std::cout << "+-----+----------+----------+----------+" << std::endl;
    std::cout << "|index|first-name|last-name | nickname |" << std::endl;
    std::cout << "+-----+----------+----------+----------+" << std::endl;
    for (size_t i = 0; i < 4; i++)
    {
        std::cout << "|" << i + 1 << "    |";
        print_ten(this->c[i].get_first_name());
        std::cout << "|";
        print_ten(this->c[i].get_last_name());
        std::cout << "|";
        print_ten(this->c[i].get_nickname());
        std::cout << "|" << std::endl;
        std::cout << "+-----+----------+----------+----------+" << std::endl;
    }
    size_t i;
    do
    {
        std::cout << "input index number:";
        std::string s;
        std::cin >> s;
        i = (size_t) atoi(s.c_str());
    } while (i > 0 && i <= MAX_CONTACTS);
    std::cout << "index\t:" << i << std::endl;
    i--;
    std::cout << "first name\t:" << this->c[i].get_first_name() << std::endl;
    std::cout << "last name\t:" << this->c[i].get_last_name() << std::endl;
    std::cout << "nickname\t:" << this->c[i].get_nickname() << std::endl;
    std::cout << "phone number\t:" << this->c[i].get_phone_number() << std::endl;
    std::cout << "darkest secret\t:" << this->c[i].get_darkest_secret() << std::endl;
}
