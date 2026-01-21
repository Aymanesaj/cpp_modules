#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        RPN::errorAndExit();
    RPN rpn(av[1]);
}