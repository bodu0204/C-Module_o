#include "Form.hpp"

std::ostream &operator<<(std::ostream &os, Form const &f)
{
    if (f.getSign())
        os << f.getName() << "is signed ";
    else
        os << f.getName() << "isn\'t signed ";
    return os;
}

const char* Form::GradeTooHighException::what() const _NOEXCEPT{return "Form::GradeTooHighException";}
const char* Form::GradeTooLowException::what() const _NOEXCEPT{return "Form::GradeTooLowException";}

std::string Form::getName() const{return this->name;}
bool Form::getSign() const{return this->sign;}
unsigned Form::getGradeSing() const{return this->grade_s;}
unsigned Form::getGradeExecute() const{return this->grade_e;}

void Form::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() <= this->grade_s)
        this->sign = true;
    else
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
