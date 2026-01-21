#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
private:
    std::stack<int> rpn;
public:
    RPN();
    RPN(const RPN& other);
	RPN& operator=(const RPN& other);
    ~RPN();
    RPN(char *av);
    void            operate(char *av);
    void            parse(char *av);
    bool            isValid(char c);
    static void     errorAndExit( void );
};

#endif