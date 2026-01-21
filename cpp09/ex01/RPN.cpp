#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(const RPN& other)
{
    operator=(other);
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other){
        rpn = other.rpn;
    }
    return (*this);
}

RPN::~RPN() { }

RPN::RPN(char *av)
{
    parse(av);
    operate(av);
}

void    RPN::errorAndExit( void )
{
    std::cerr << "Error" << std::endl;
    std::exit(1);
}

bool    RPN::isValid(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

void    RPN::parse(char *av)
{
    size_t i = 0;
    while (av[i] && std::isspace(av[i])) ++i;
    if (!av[i])
        errorAndExit(); 
    for (; av[i]; ++i)
    {
        if (std::isspace(av[i]))
            continue;
        if (isValid(av[i]) || std::isdigit(av[i]))
        {
            ++i;
            if ((!av[i] || !std::isspace(av[i]))) break;
        }
        else
            break;
    }
    if (av[i])
        errorAndExit();
}

void    RPN::operate(char *av)
{
    int a, b, i = 0;
    while (av[i])
    {
        if (std::isdigit(av[i]))
            rpn.push(av[i] - 48);
        else if (isValid(av[i]))
        {
            if (rpn.size() < 2)
                errorAndExit();
            b = rpn.top();
            rpn.pop();
            a = rpn.top();
            rpn.pop();
            if (av[i] == '+')
                a += b;
            else if (av[i] == '-')
                a -= b;
            else if (av[i] == '*')
                a *= b;
            else
            {
                if (!b)
                    errorAndExit();
                a /= b;
            }
            rpn.push(a);
        }
        i++;
    }
    if (rpn.size() != 1)
        errorAndExit();
    std::cout << rpn.top() << std::endl; 
}