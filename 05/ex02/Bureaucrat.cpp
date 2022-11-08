#include "Form.hpp"
#include "Bureaucrat.hpp"

void Bureaucrat::signForm(Form &f)
{
    if (f.getSign())
    {
        std::cout << this->name << " couldn\'t sign "<< f.getName() <<" because it's signed." << std::endl;
        return ;
    }
    else
    {
        try{
            f.beSigned(*this);
        }
        catch(const std::exception& e){
            std::cerr << e.what() << '\n';
            return ;
        }
        std::cout << this->name << " signed " << f.getName() <<"." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}


const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT{return "Bureaucrat::GradeTooHighException";}
const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT{return "Bureaucrat::GradeTooLowException";}

void Bureaucrat::executeForm(Form const &f)
{
    try
    {
        f.execute(*this);
        std::cout << this->getName() << " executed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return ;
    }
}

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
