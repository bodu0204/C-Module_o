#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:

public:
    void execute(Bureaucrat const &) const;
    PresidentialPardonForm();
    PresidentialPardonForm(std::string namem);
    PresidentialPardonForm(PresidentialPardonForm const &);
    PresidentialPardonForm const & operator=(PresidentialPardonForm const &);
    ~PresidentialPardonForm();
};

#endif