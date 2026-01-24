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
#include <climits>
#include <sstream>
#include <utility>
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> nums_v;
    std::deque<int> nums_d;
public:
    PmergeMe();
    PmergeMe(char **av);
    PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    static void     errorAndExit( void );
    void    parse(char **av);
    bool toIntSafe(const std::string &s, int &out);
    void    sort_vec( std::vector<int> &nums );
    void    sort_deq( std::deque<int> &nums );
};

#endif