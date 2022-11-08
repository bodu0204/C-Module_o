#include <string>
#include <iostream>
#include "iter.hpp"

class some_class
{
private:
    int i;
public:
    int get_i()const;
    bool operator<(some_class const &);
    bool operator<=(some_class const &);
    bool operator>(some_class const &);
    bool operator>=(some_class const &);

    some_class();
    some_class(int);
    some_class(some_class const &);
    some_class const &operator=(some_class const &);
    ~some_class();
};

std::ostream &operator<<(std::ostream &, some_class const &);

int some_class::get_i()const{return (this->i);}

bool some_class::operator<(some_class const &s){return(this->get_i()<s.get_i());}
bool some_class::operator<=(some_class const &s){return(this->get_i()<=s.get_i());}
bool some_class::operator>(some_class const &s){return(this->get_i()>s.get_i());}
bool some_class::operator>=(some_class const &s){return(this->get_i()>=s.get_i());}

some_class::some_class()
{
    this->i = 0;
}

some_class::some_class(int n)
{
    this->i = n;
}

some_class::some_class(some_class const &s)
{
    this->i = s.get_i();
}

some_class const &some_class::operator=(some_class const &s)
{
    this->i = s.get_i();
    return (*this);
}

some_class::~some_class(){}

std::ostream &operator<<(std::ostream &os, some_class const &s)
{
    os<<s.get_i();
    return (os);
}

void print (some_class const &s)
{
    std::cout<<s.get_i()<<std::endl;
}

void print(int const &i)
{
    std::cout<<i<<std::endl;
}


int main() {
    std::cout<< "=========================================" << std::endl;
    int arri[5];
    for (size_t i = 0; i < 5; i++)
    {
        arri[i] = i + 1;
        std::cout<<arri[i]<<",";
    }
    std::cout<<std::endl;
    std::cout<< "--iter(arri, 5, print)--" << std::endl;
    iter(arri, 5, print);
    std::cout<<std::endl;

    std::cout<< "=========================================" << std::endl;
    some_class arrs[5];
    for (size_t i = 0; i < 5; i++)
    {
        arrs[i] = some_class((int)i + 1);
        std::cout<<arrs[i]<<",";
    }
    std::cout<<std::endl;
    std::cout<< "--iter(arrs, 5, print)--" << std::endl;
    iter(arrs, 5, print);

    std::cout<< std::endl;

    return (0);
}
