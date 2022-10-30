#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    switch (rand() % 3)
    {
    case 0:
        return (static_cast<Base*>(new A()));
    case 1:
        return (static_cast<Base*>(new B()));
    case 2:
        return (static_cast<Base*>(new C()));
    }
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Type-A " ;
    if (dynamic_cast<B *>(p))
        std::cout << "Type-B " ;
    if (dynamic_cast<C *>(p))
        std::cout << "Type-C " ;
}

void identify(Base& p)
{
    unsigned i = 0b111;
    try
    {
        A &aa = dynamic_cast<A &>(p);
        (void)aa;
    }
    catch(const std::bad_cast& e)
    {
        (void)e;
        i &= 0b110U;
    }
    try
    {
        B &bb = dynamic_cast<B &>(p);
        (void)bb;
    }
    catch(const std::bad_cast& e)
    {
        (void)e;
        i &= 0b101U;
    }
    try
    {
        C &cc = dynamic_cast<C &>(p);
        (void)cc;
    }
    catch(const std::bad_cast& e)
    {
        (void)e;
        i &= 0b011U;
    }
    if (i & 0b001U)
        std::cout << "Type-A " ;
    if (i & 0b010U)
        std::cout << "Type-B " ;
    if (i & 0b100U)
        std::cout << "Type-C " ;
}
