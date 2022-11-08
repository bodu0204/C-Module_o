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

#endif