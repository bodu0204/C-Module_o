#ifndef FOPRM_HPP
#define FOPRM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string const name;
    bool sign;
    unsigned const grade_s;
    unsigned const grade_e;
public:
    class GradeTooHighException :public std::exception{
        const char* what() const _NOEXCEPT;
    };
    class GradeTooLowException :public std::exception{
        const char* what() const _NOEXCEPT;
    };
    std::string getName() const;
    bool getSign() const;
    unsigned getGradeSing() const;
    unsigned getGradeExecute() const;
    void beSigned(Bureaucrat const &);
    Form();
    Form(std::string namem, unsigned grade_s, unsigned grade_e);
    Form(Form const &);
    Form const &operator=(Form const &);
    ~Form();
};

std::ostream &operator<<(std::ostream &, Form const &);

#endif