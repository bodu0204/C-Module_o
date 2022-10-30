#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <random>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:

public:
    void execute(Bureaucrat const &) const;
    RobotomyRequestForm();
    RobotomyRequestForm(std::string namem);
    RobotomyRequestForm(RobotomyRequestForm const &);
    RobotomyRequestForm const & operator=(RobotomyRequestForm const &);
    ~RobotomyRequestForm();
};

#endif