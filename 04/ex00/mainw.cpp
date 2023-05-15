#include "Animal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

//using namespace std;
int main() {
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* j = new WrongDog();
    const WrongAnimal* i = new WrongCat();
    std::cout <<"meta->getType():"<< meta->getType() << " " << std::endl;
    std::cout <<"j->getType():"<< j->getType() << " " << std::endl;
    std::cout <<"i->getType():"<< i->getType() << " " << std::endl;
    i->makeSound(); //will output the Wrongcat sound!
    j->makeSound();
    meta->makeSound();
    const WrongAnimal& mmeta = *meta;
    const WrongAnimal& jj = *j;
    const WrongAnimal& ii = *i;
    std::cout <<"mmeta.getType():"<< mmeta.getType() << " " << std::endl;
    std::cout <<"jj.getType():"<< jj.getType() << " " << std::endl;
    std::cout <<"ii.getType():"<< ii.getType() << " " << std::endl;
    ii.makeSound(); //will output the Wrongcat sound!
    jj.makeSound();
    mmeta.makeSound();
    delete meta;
    delete j;
    delete i;
    WrongAnimal A("some-type");
    WrongCat C;
    WrongDog D;
    std::cout <<"A.getType():"<< A.getType() << " " << std::endl;
    std::cout <<"C.getType():"<< C.getType() << " " << std::endl;
    std::cout <<"D.getType():"<< D.getType() << " " << std::endl;
    D.makeSound(); //will output the cat sound!
    C.makeSound();
    A.makeSound();
#ifdef ERROR
    const Animal* w = new WrongDog();
    delete w;
#endif
    return 0;
}