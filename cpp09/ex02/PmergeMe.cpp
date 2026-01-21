#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) 
{
    operator=(other);
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other){
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(char *av)
{
	parse(av);
}

bool PmergeMe::toIntSafe(const std::string &s, int &out) {
    errno = 0;
    char *endptr = 0;

    long val = std::strtol(s.c_str(), &endptr, 10);
    if (endptr == s.c_str() || *endptr != '\0' || errno == ERANGE
        || val < INT_MIN || val > INT_MAX)
        return false;
    out = (int)val;
    return true;
}

void     PmergeMe::parse( char *av )
{
	size_t i = 0;
    while (av[i] && std::isspace(av[i])) ++i;
    if (!av[i])
        errorAndExit();
    for (; av[i]; ++i)
        if (!std::isspace(av[i]) && !std::isdigit(av[i])) break;
    if (av[i])
        errorAndExit();
    std::stringstream ss(av);
    int x;
    std::string str;
    while (ss >> str)
    {
        if (!toIntSafe(str, x))
            errorAndExit();
        nums_v.push_back(x);
        nums_d.push_back(x);
    }
}

void     PmergeMe::errorAndExit( void )
{
    std::cerr << "Error" << std::endl;
    std::exit(1);
}

int PmergeMe::ft_atoi(std::string& num)
{
	errno = 0;
	char *endptr = NULL;
	long rate = std::strtol(num.c_str(), &endptr, 10);
	if (*endptr != '\0' || endptr == num.c_str() || errno == ERANGE || rate > std::numeric_limits<int>::max()
		|| rate < 0)
		return (-1);
	return (rate);
}