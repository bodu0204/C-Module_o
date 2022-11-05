#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{    
public:
    class NoForm :public std::exception{
        const char* what() const _NOEXCEPT;
    };
        
    Form *makeForm(std::string, std::string);
    Intern();
    Intern(Intern const&);
    Intern const & operator=(Intern const&);
    ~Intern();
};

const char* Intern::NoForm::what() const _NOEXCEPT{return "Intern::NoForm";}

Form *Intern::makeForm(std::string name, std::string terget)
{
    unsigned s = 0;
    s += (terget == "robotomy request")?1:0;
    s += (terget == "presidential pardonForm")?2:0;
    s += (terget == "shrubbery creation")?3:0;
    switch (s)
    {
    case 1:
        return (new RobotomyRequestForm(terget));    
    case 2:
        return (new PresidentialPardonForm(terget));    
    case 3:
        return (new ShrubberyCreationForm(terget));    
    default:
        throw NoForm();
    }
}

Intern::Intern(){}
Intern::Intern(Intern const&){}
Intern const & Intern::operator=(Intern const&){return *this;}
Intern::~Intern(){}

#endif