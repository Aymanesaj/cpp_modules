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

void     PmergeMe::parse( char *av )
{
	// size_t i = 0;
    // while (av[i] && std::isspace(av[i])) ++i;
    // if (!av[i])
    //     errorAndExit(); 
    // for (; av[i]; ++i)
    // {
    //     if (std::isspace(av[i]))
    //         continue;
    //     if (std::isdigit(av[i]))
    //     {
    //         ++i;
    //         if ((!av[i] || !std::isspace(av[i]))) break;
    //     }
    //     else
    //         break;
    // }
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