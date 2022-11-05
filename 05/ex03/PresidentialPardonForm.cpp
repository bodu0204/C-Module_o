#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::cout << executor.getName() <<" has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm():Form("no_name", 25, 5){}
PresidentialPardonForm::PresidentialPardonForm(std::string namem):Form(namem, 25, 5){}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &p):Form(p.getName(), 25, 5){}
PresidentialPardonForm const & PresidentialPardonForm::operator=(PresidentialPardonForm const &p){(void)p;return *this;}
PresidentialPardonForm::~PresidentialPardonForm(){}
