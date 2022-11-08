#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    while (true)
    {
        try
        {
            std::string s;
            unsigned n;
            Intern i;

            std::cout<<"Bureaucrat(name, grade):";std::cin>>s>>n;
            if (std::cin.eof() || std::cin.fail())
                return 0;
            Bureaucrat b(s, n);

            std::string na, tr;
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Intern::makeForm(std::string name, ***):";std::getline(std::cin, na);
            if (std::cin.eof() || std::cin.fail())
                return 0;
            std::cout<<"Intern::makeForm("<<na<<", std::string terget):";std::getline(std::cin, tr);
            if (std::cin.eof() || std::cin.fail())
                return 0;
            Form *fp = i.makeForm(na, tr);

            b.signForm(*fp);
            b.executeForm(*fp);
        }
        catch(const std::exception& e)
        {
           std::cerr << e.what() << '\n';
        }
    }
    return 0;
}