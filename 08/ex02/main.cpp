#include <string>
#include <iostream>
#include "Array.hpp"

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

some_class ten_times (some_class s)
{
    return(some_class(s.get_i() * 10));
}

int ten_times(int i)
{
    return(i * 10);
}


int main() {
    std::cout<< "=========================================" << std::endl;
    Array<int> arri(5);
    std::cout<<"arri: ";
    for (size_t i = 0; i < 5; i++)
    {
        arri[i] = i + 1;
        std::cout<<arri[i]<<",";
    }
    std::cout<< "arri.size()=" << arri.size() <<std::endl;
    
    Array<int> arri_cpy1(arri);
    Array<int> arri_cpy2;
    arri_cpy2 = arri;
    std::cout<< "--make cpy--" << std::endl;

    for (size_t i = 0; i < 5; i++)
    {
        arri[i] = arri[i] + arri[i];
    }
    std::cout<< "--edit arri--" << std::endl;

    std::cout<<"arri_cpy1: ";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout<<arri_cpy1[i]<<",";
    }
    std::cout<< "arri.size()=" << arri.size() <<std::endl;
    std::cout<<"arri_cpy2: ";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout<<arri_cpy2[i]<<",";
    }
    std::cout<< "arri.size()=" << arri.size() <<std::endl;

    std::cout<<"arri: ";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout<<arri[i]<<",";
    }
    std::cout<< "arri.size()=" << arri.size() <<std::endl;
    
    std::cout<< "=========================================" << std::endl;
    Array<some_class> arrs(5);
    std::cout<<"arrs: ";
    for (size_t i = 0; i < 5; i++)
    {
        arrs[i] = some_class((int)i + 1);
        std::cout<<arrs[i]<<",";
    }
    std::cout<< "arrs.size()=" << arrs.size() <<std::endl;
    
    Array<some_class> arrs_cpy1(arrs);
    Array<some_class> arrs_cpy2;
    arrs_cpy2 = arrs;
    std::cout<< "--make cpy--" << std::endl;

    for (size_t i = 0; i < 5; i++)
    {
        arrs[i] = ten_times(arrs[i]);
    }
    std::cout<< "--edit arrs--" << std::endl;

    std::cout<<"arrs_cpy1: ";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout<<arrs_cpy1[i]<<",";
    }
    std::cout<< "arrs.size()=" << arrs.size() <<std::endl;
    std::cout<<"arrs_cpy2: ";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout<<arrs_cpy2[i]<<",";
    }
    std::cout<< "arrs.size()=" << arrs.size() <<std::endl;

    std::cout<<"arrs: ";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout<<arrs[i]<<",";
    }
    std::cout<< "arrs.size()=" << arrs.size() <<std::endl;

    return (0);
}
