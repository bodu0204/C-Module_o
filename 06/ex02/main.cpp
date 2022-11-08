#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Identify.hpp"
#include <unistd.h>

int main() {

    std::string s;

    do
    {
        Base *p = generate();
        std::cout<<"Base *generate(void) : "<< static_cast<void*>(p)<<std::endl;
        std::cout<<"void identify(Base* p) : "; identify(p); std::cout<<std::endl;
        std::cout<<"void identify(Base& p) : "; identify(*p); std::cout<<std::endl;
        if (dynamic_cast<A *>(p))
            delete dynamic_cast<A *>(p);
        else if (dynamic_cast<B *>(p))
            delete dynamic_cast<B *>(p);
        else if (dynamic_cast<C *>(p))
            delete dynamic_cast<C *>(p);
        std::getline(std::cin, s);
    } while (!std::cin.eof() && !std::cin.fail());
    return 0;
}