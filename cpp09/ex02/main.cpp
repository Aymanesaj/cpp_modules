#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        PmergeMe::errorAndExit();
    PmergeMe sort(av[1]);
}