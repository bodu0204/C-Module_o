#include "RPN.hpp"

RPN::RPN():answer(""),err(false){}
RPN::RPN(std::string str):answer(""),err(false){this->calculate(str);}
RPN::RPN(RPN const &src){*this = src;}
RPN const& RPN::operator=(RPN const&src)
{
    this->answer = src.answer;
    this->err = src.err;
    return(*this);
}

void RPN::calculate(std::string str)
{
    std::stack<int> work;
    std::stringstream stm;

    stm << str;
    while(!(stm.eof()||stm.fail()))
    {
        stm>>str;
        if (str.size() > 1)
        {
            err = true;
            return;
        }
        else if(!str.size())
            continue;
        if (isdigit(str[0]))
        {
            work.push(atoi(str.c_str()));
            continue;
        }
        if (work.size() < 2)
        {
            err = true;
            return;
        }
        int a = work.top(); 
        work.pop();
        switch (str[0])
        {
        case '+':
            work.top() += a;
            break;
        case '-':
            work.top() -= a;
            break;
        case '*':
            work.top() *= a;
            break;
        case '/':
            if (a == 0) {err = true; return;}
            work.top() /= a;
            break;
        default:
            err = true;
            return;
        }
    }
    if (work.size() != 1)
    {
        err = true;
        return;
    }
    stm.clear();
    stm << work.top();
    stm >> this->answer;
    return ;
}

std::string RPN::get_answer() const
{
    if (err)
        return(std::string("Error"));
    return(this->answer);
}


RPN::~RPN(){}
