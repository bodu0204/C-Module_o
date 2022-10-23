#include <iostream>
#include "PhoneBook.hpp"

size_t PhoneBook::idx (size_t i)
{
    return ((i + s) % MAX_CONTACTS);
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
        if (std::cin.eof())
            return ;
        std::cout << "input first name:";
        std::cin >> str;
    } while (c[idx(l - 1)].set_first_name(str));
    do
    {
        if (std::cin.eof())
            return ;
        std::cout << "input last name:";
        std::cin >> str;
    } while (c[idx(l - 1)].set_last_name(str));
    do
    {
        if (std::cin.eof())
            return ;
        std::cout << "input nickname:";
        std::cin >> str;
    } while (c[idx(l - 1)].set_nickname(str));
    do
    {
        if (std::cin.eof())
            return ;
        std::cout << "input phone number:";
        std::cin >> str;
    } while (c[idx(l - 1)].set_phone_number(str));
    do
    {
        if (std::cin.eof())
            return ;
        std::cout << "input darkest secret:";
        std::cin >> str;
    } while (c[idx(l - 1)].set_darkest_secret(str));
}

void PhoneBook::search(void)
{
    if (!l)
    {
        std::cout << "no data." << std::endl;
        return ;
    }
    std::cout << "+-----+----------+----------+----------+" << std::endl;
    std::cout << "|index|first-name|last-name | nickname |" << std::endl;
    std::cout << "+-----+----------+----------+----------+" << std::endl;
    for (size_t i = 0; i < ((this->l < 4) ? (this->l) : (4)); i++)
    {
        std::cout << "|" << i + 1 << "    |";
        print_ten(this->c[idx(i)].get_first_name());
        std::cout << "|";
        print_ten(this->c[idx(i)].get_last_name());
        std::cout << "|";
        print_ten(this->c[idx(i)].get_nickname());
        std::cout << "|" << std::endl;
        std::cout << "+-----+----------+----------+----------+" << std::endl;
    }
    size_t i;
    do
    {
        if (std::cin.eof())
            return ;
        std::cout << "input index number:";
        std::string s;
        std::cin >> s;
        i = (size_t) atoi(s.c_str());
    } while (i < 1 || i > l);
    std::cout << "index\t\t:" << i << std::endl;
    i--;
    std::cout << "first name\t:" << this->c[idx(i)].get_first_name() << std::endl;
    std::cout << "last name\t:" << this->c[idx(i)].get_last_name() << std::endl;
    std::cout << "nickname\t:" << this->c[idx(i)].get_nickname() << std::endl;
    std::cout << "phone number\t:" << this->c[idx(i)].get_phone_number() << std::endl;
    std::cout << "darkest secret\t:" << this->c[idx(i)].get_darkest_secret() << std::endl;
}
