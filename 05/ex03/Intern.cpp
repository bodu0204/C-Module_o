#include "Intern.hpp"

const char* Intern::NoForm::what() const _NOEXCEPT{return "Intern::NoForm";}

Form *Intern::makeForm(std::string name, std::string terget)
{
    unsigned s = 0;
    s += (name == "robotomy request")?1:0;
    s += (name == "presidential pardonForm")?2:0;
    s += (name == "shrubbery creation")?3:0;
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
