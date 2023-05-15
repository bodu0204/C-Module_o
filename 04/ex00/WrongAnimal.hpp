#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string type;
public:
    virtual void makeSound() const;
    std::string getType() const;
    WrongAnimal const &operator=(WrongAnimal const &);
    WrongAnimal();
    WrongAnimal(WrongAnimal const &);
    WrongAnimal(std::string);
    virtual ~WrongAnimal();
};

#endif