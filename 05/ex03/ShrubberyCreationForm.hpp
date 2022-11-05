#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:

public:
    void execute(Bureaucrat const &) const;
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string namem);
    ShrubberyCreationForm(ShrubberyCreationForm const &);
    ShrubberyCreationForm const & operator=(ShrubberyCreationForm const &);
    ~ShrubberyCreationForm();
};

#define ASCII_TREES \
"\
                      ___\n\
                _,-'\"\"   \"\"\"\"`--.\n\
             ,-'          __,,-- \\\n\
           ,'    __,--\"\"\"\"dF      )\n\
          /   .-\"Hb_,--\"\"dF      /\n\
        ,'       _Hb ___dF\"-._,-'\n\
      ,'      _,-\"\"\"\"   \"\"--..__\n\
     (     ,-'                  `.\n\
      `._,'     _   _             ;\n\
       ,'     ,' `-'Hb-.___..._,-'\n\
       \\    ,'\"Hb.-'HH`-.dHF\"\n\
        `--'   \"Hb  HH  dF\"\n\
                \"Hb HH dF\n\
                 \"HbHHdF\n\
                  |HHHF\n\
                  |HHH|\n\
                  |HHH|\n\
                  |HHH|\n\
                  |HHH|\n\
                  dHHHb\n\
                .dFd|bHb.               o\n\
      o       .dHFdH|HbTHb.          o /\n\
\\  Y  |  \\__,dHHFdHH|HHhoHHb.__/  \\  Y\n\
##########################################\n\
"
#endif