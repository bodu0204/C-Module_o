#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

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
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}


const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT{return "Bureaucrat::GradeTooHighException";}
const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT{return "Bureaucrat::GradeTooLowException";}

std::string Bureaucrat::getName() const{return this->name;}
unsigned Bureaucrat::getGrade() const{return this->grade;}

Bureaucrat &Bureaucrat::operator++()
{
    if (this->grade <= 1)
        throw GradeTooHighException();
    this->grade--;
    return *this;
}

Bureaucrat const &Bureaucrat::operator++(int)
{
    if (this->grade <= 1)
        throw GradeTooHighException();
    Bureaucrat b(this->name, this->grade);
    this->grade--;
    return *this;
}

Bureaucrat &Bureaucrat::operator--()
{
    if (this->grade >= 150)
        throw GradeTooLowException();
    this->grade++;
    return *this;
}

Bureaucrat const &Bureaucrat::operator--(int)
{
    if (this->grade >= 150)
        throw GradeTooLowException();
    Bureaucrat b(this->name, this->grade);
    this->grade++;
    return *this;
}

Bureaucrat::Bureaucrat():name("no-name")
{
    this->grade = 150U;
}

Bureaucrat::Bureaucrat(std::string name, unsigned grade):name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &b):name(b.getName())
{
    this->grade = b.getGrade();
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &b)
{
    this->grade = b.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

#endif