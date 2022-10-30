#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    
    B b;
    Base *p = &b;

    try
    {
        A &aa = dynamic_cast<A &>(b);
        (void)aa;
    }
    catch(const std::bad_cast& e)
    {
        (void)e;
        std::cout<<"notA"<<std::endl;
    }
    try
    {
        B &bb = dynamic_cast<B &>(b);
        (void)bb;
    }
    catch(const std::bad_cast& e)
    {
        (void)e;
        std::cout<<"notB"<<std::endl;
    }
    try
    {
        C &cc = dynamic_cast<C &>(b);
        (void)cc;
    }
    catch(const std::bad_cast& e)
    {
        (void)e;
        std::cout<<"notC"<<std::endl;
    }
    
    std::cout<<"A"<< dynamic_cast<A *>(p)<<std::endl;
    std::cout<<"B"<< dynamic_cast<B *>(p)<<std::endl;
    std::cout<<"C"<< dynamic_cast<C *>(p)<<std::endl;
    return 0;
}