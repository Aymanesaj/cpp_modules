#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <deque>
#include <cerrno>
#include <limits>

class PmergeMe
{
private:
public:
    PmergeMe();
    PmergeMe(char *av);
    PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    int ft_atoi(std::string& num);
    static void     errorAndExit( void );
    void    parse(char *av);
};

#endif