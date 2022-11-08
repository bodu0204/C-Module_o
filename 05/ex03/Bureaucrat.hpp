#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    std::string const name;
    unsigned grade;

public:
    class GradeTooHighException :public std::exception{
        const char* what() const _NOEXCEPT;
    };
    class GradeTooLowException :public std::exception{
        const char* what() const _NOEXCEPT;
    };
    void executeForm(Form const&);
    void signForm(Form &);
    std::string getName() const;
    unsigned getGrade() const;
    Bureaucrat &operator++();
    Bureaucrat const &operator++(int);
    Bureaucrat &operator--();
    Bureaucrat const &operator--(int);
    Bureaucrat();
    Bureaucrat(std::string name, unsigned grade);
    Bureaucrat const &operator=(Bureaucrat const &);
    Bureaucrat(Bureaucrat const &);
    ~Bureaucrat();
};

std::ostream &operator<<(std::ostream &, Bureaucrat const &);

#endif