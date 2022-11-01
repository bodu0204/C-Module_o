#include <string>
#include <iostream>
#include "whatever.hpp"


int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0; 
}

/* 
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

int main() {
    std::cout<< "=========================================" << std::endl;
    int ia(5);
    int ib(3);
    std::cout<< "ia:" << ia << " ib:" << ib << std::endl;
    std::cout<< "min(ia, ib): " << min(ia, ib) << std::endl;
    std::cout<< "max(ia, ib): " << max(ia, ib) << std::endl;
    std::cout<< "--swap(ia, ib)--" << std::endl;
    swap(ia, ib);
    std::cout<< "ia:" << ia << " ib:" << ib << std::endl;

    std::cout<< "=========================================" << std::endl;
    std::string sa = "hello";
    std::string sb = "world";
    std::cout<< "sa:" << sa << " sb:" << sb << std::endl;
    std::cout<< "min(sa, sb): " << min(sa, sb) << std::endl;
    std::cout<< "max(sa, sb): " << max(sa, sb) << std::endl;
    std::cout<< "--swap(sa, sb)--" << std::endl;
    swap(sa, sb);
    std::cout<< "sa:" << sa << " sb:" << sb << std::endl;

    std::cout<< "=========================================" << std::endl;
    some_class ca(5);
    some_class cb(3);
    std::cout<< "ca:" << ca << " cb:" << cb << std::endl;
    std::cout<< "min(ca, cb): " << min(ca, cb) << std::endl;
    std::cout<< "max(ca, cb): " << max(ca, cb) << std::endl;
    std::cout<< "--swap(ca, cb)--" << std::endl;
    swap(ca, cb);
    std::cout<< "ca:" << ca << " cb:" << cb << std::endl;

    std::cout<< std::endl;

    return (0);
}
 */