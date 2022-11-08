#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    while (true)
    {
        try
        {
            std::string s;
            unsigned n;

            std::cout<<"Bureaucrat(name, grade):";std::cin>>s>>n;
            if (std::cin.eof() || std::cin.fail())
                return 0;
            Bureaucrat b(s, n);
            std::string sn;
            std::cout<<"ShrubberyCreationForm(name):";std::cin>>sn;
            if (std::cin.eof() || std::cin.fail())
                return 0;
            std::string rn;
            std::cout<<"RobotomyRequestForm(name):";std::cin>>rn;
            if (std::cin.eof() || std::cin.fail())
                return 0;
            std::string pn;
            std::cout<<"PresidentialPardonForm(name):";std::cin>>pn;
            if (std::cin.eof() || std::cin.fail())
                return 0;
            ShrubberyCreationForm sf(sn);
            RobotomyRequestForm rf(rn);
            PresidentialPardonForm pf(pn);
            b.signForm(sf);
            b.executeForm(sf);
            b.signForm(rf);
            b.executeForm(rf);
            b.signForm(pf);
            b.executeForm(pf);
        }
        catch(const std::exception& e)
        {
           std::cerr << e.what() << '\n';
        }
    }
    return 0;
}