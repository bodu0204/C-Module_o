#include "Intern.hpp"

const char* Intern::NoForm::what() const _NOEXCEPT{return "Intern::NoForm";}

Form *Intern::makeForm(std::string name, std::string terget)
{
    unsigned s = 0;
    s += (name == "robotomy request")?1:0;
    s += (name == "presidential pardon")?2:0;
    s += (name == "shrubbery creation")?3:0;
    switch (s)
    {
    case 1:
        std::cout<<"Intern creates RobotomyRequestForm"<<std::endl;
        return (new RobotomyRequestForm(terget));    
    case 2:
        std::cout<<"Intern creates PresidentialPardonForm"<<std::endl;
        return (new PresidentialPardonForm(terget));    
    case 3:
        std::cout<<"Intern creates ShrubberyCreationForm"<<std::endl;
        return (new ShrubberyCreationForm(terget));    
    default:
        throw NoForm();
    }
}

Intern::Intern(){}
Intern::Intern(Intern const&){}
Intern const & Intern::operator=(Intern const&){return *this;}
Intern::~Intern(){}
