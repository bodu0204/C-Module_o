#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    for (size_t i = 0; i < 7; i++)
    {
        std::cout << "\a"; fflush(stdout);
        usleep(300000);
    }
    std::cout << this->getName();
    if (rand() % 2)
        std::cout << " has been robotomized." << std::endl;
    else
        std::cout <<" is failed to robotomy." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm():Form("no_name", 72, 45){}
RobotomyRequestForm::RobotomyRequestForm(std::string namem):Form(namem, 72, 45){}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &p):Form(p.getName(), 72, 45){}
RobotomyRequestForm const & RobotomyRequestForm::operator=(RobotomyRequestForm const &p){(void)p;return *this;}
RobotomyRequestForm::~RobotomyRequestForm(){}
