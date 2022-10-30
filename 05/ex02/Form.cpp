#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream &operator<<(std::ostream &os, Form const &f)
{
    if (f.getSign())
        os << f.getName() << "is signed " << std::endl;
    else
        os << f.getName() << "isn\'t signed " << std::endl;
    return os;
}

const char* Form::GradeTooHighException::what() const _NOEXCEPT{return "Form::GradeTooHighException";}
const char* Form::GradeTooLowException::what() const _NOEXCEPT{return "Form::GradeTooLowException";}
const char* Form::NoSignException::what() const _NOEXCEPT{return "Form::NoSignException";}

std::string Form::getName() const{return this->name;}
bool Form::getSign() const{return this->sign;}
unsigned Form::getGradeSing() const{return this->grade_s;}
unsigned Form::getGradeExecute() const{return this->grade_e;}

void Form::beSigned(Bureaucrat const &b)
{
    if (this->sign)
        std::cout << b.getName() << "couldn\'t sign "<< this->getName() <<" because it's signed." << std::endl;
    else if (b.getGrade() <= this->grade_s)
    {
        std::cout << b.getName() << " signed " << this->getName() <<"." << std::endl;
        this->sign = true;
    }
    else
        throw GradeTooLowException();
}

void Form::execute(Bureaucrat const &b) const
{
    if (!this->sign)
        throw NoSignException();
    else if (b.getGrade() > this->grade_e)
        throw GradeTooLowException();
}

Form::Form():name("no-name"),grade_s(150),grade_e(150)
{
    this->sign = false;
}

Form::Form(std::string namem, unsigned grade_sign , unsigned grade_execute):name(namem),grade_s(grade_sign),grade_e(grade_execute)
{
    if (grade_sign < 1 || grade_execute < 1)
        throw GradeTooHighException();
    else if (grade_sign > 150|| grade_execute > 150)
        throw GradeTooLowException();
    this->sign = false;
}

Form::Form(Form const &f):name(f.getName()),grade_s(f.getGradeSing()),grade_e(f.getGradeExecute())
{
    this->sign = f.getSign();
}

Form const &Form::operator=(Form const &f){(void)f;return (*this);}

Form::~Form(){}
