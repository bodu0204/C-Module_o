#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    while (1)
    {
        try
        {
            std::string s;
            unsigned n;

            std::cout<<"Bureaucrat(name, grade):";std::cin>>s>>n;
            if (std::cin.eof())
                return 0;
            Bureaucrat b(s, n);
            std::string na;
            unsigned gs;
            unsigned ge;
            std::cout<<"Form(name, grade_sign, grade_execute):";std::cin>>na>>gs>>ge;
            if (std::cin.eof())
                return 0;
            Form f(na, gs, ge);
            f.beSigned(b);
            f.beSigned(b);
        }
        catch(const std::exception& e)
        {
           std::cerr << e.what() << '\n';
        }
    }
    return 0;
}