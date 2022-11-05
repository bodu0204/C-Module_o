#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::fstream f;
	f.open(std::string(executor.getName() + "_shrubbery"), std::ios_base::out);
	f << ASCII_TREES << std::endl;
	f.close();
}


ShrubberyCreationForm::ShrubberyCreationForm():Form("no_name", 145, 137){}
ShrubberyCreationForm::ShrubberyCreationForm(std::string namem):Form(namem, 145, 137){}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &p):Form(p.getName(), 145, 137){}
ShrubberyCreationForm const & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &p){(void)p;return *this;}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
