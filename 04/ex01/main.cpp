#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

//using namespace std;
int main(int argc , char *argv[]) {
    (void) argc;
    (void) argv;
    Animal *ap[10];

    for (size_t i = 0; i < 10; i++)
    {
        if (i % 2)
            ap[i] = new Cat;
        else
            ap[i] = new Dog;
    }
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << "ap[" << i << "]->makeSound\t"; ap[i]->makeSound();
    }
    for (size_t i = 0; i < 10; i++)
        delete ap[i];        
    std::cout << "+----------------------------------------------------------------+" << std::endl;
    Cat *c = new Cat;
    Cat *c_cpy = new Cat(*c);
    std::cout << "Cat *c" << (void *) c <<std::endl;
    std::cout << "c->get_brainp()" << (void *) c->get_brainp() <<std::endl;
    std::cout << "Cat *c_cpy" << (void *) c_cpy <<std::endl;
    std::cout << "c_cpy->get_brainp()" << (void *) c_cpy->get_brainp() <<std::endl;
    delete c;
    delete c_cpy;
    std::cout << "+----------------------------------------------------------------+" << std::endl;
    std::string cmd = "leaks ";
    std::string cmd_arg = argv[0];
    cmd += cmd_arg.substr(cmd_arg.rfind("/") + 1, cmd_arg.length() - cmd_arg.rfind("/"));
    std::cout << cmd <<std::endl;
    system(cmd.c_str());
    return 0; 
}