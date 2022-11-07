#include "Dog.hpp"
#include "Cat.hpp"

//using namespace std;
int main() {
    const Animal* meta = new Animal(); 
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout <<"meta->getType():"<< meta->getType() << " " << std::endl; 
    std::cout <<"j->getType():"<< j->getType() << " " << std::endl; 
    std::cout <<"i->getType():"<< i->getType() << " " << std::endl; 
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    const Animal& mmeta = *meta; 
    const Animal& jj = *j;
    const Animal& ii = *i;
    std::cout <<"mmeta.getType():"<< mmeta.getType() << " " << std::endl; 
    std::cout <<"jj.getType():"<< jj.getType() << " " << std::endl; 
    std::cout <<"ii.getType():"<< ii.getType() << " " << std::endl; 
    ii.makeSound(); //will output the cat sound!
    jj.makeSound();
    mmeta.makeSound();
    delete meta;
    delete j;
    delete i;
    Animal A("some-type"); 
    Cat C;
    Dog D;
    std::cout <<"A.getType():"<< A.getType() << " " << std::endl; 
    std::cout <<"C.getType():"<< C.getType() << " " << std::endl; 
    std::cout <<"D.getType():"<< D.getType() << " " << std::endl; 
    D.makeSound(); //will output the cat sound!
    C.makeSound();
    A.makeSound();
return 0; }