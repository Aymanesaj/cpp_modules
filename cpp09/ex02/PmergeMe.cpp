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

PmergeMe::PmergeMe(char **av)
{
	parse(av);
	std::cout << "Before: ";
	for (size_t i = 0; i < nums_v.size(); i++)
		std::cout << nums_v[i] << " ";
	std::cout << std::endl;
	clock_t startVec = clock();
    sort_vec(nums_v);
	clock_t endVec = clock();
	clock_t startDeq = clock();
	sort_deq(nums_d);
	clock_t endDeq = clock();
	std::cout << "After: ";
	for (size_t i = 0; i < nums_v.size(); i++)
		std::cout << nums_v[i] << " ";
	std::cout << std::endl;
    double timeVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = double(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << nums_v.size()
		<< " elements with std::[vector] : " 
		<< timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << nums_d.size()
		<< " elements with std::[deque] : "
		<< timeDeq << " us" << std::endl;
}

bool PmergeMe::toIntSafe(const std::string &s, int &out) {
    errno = 0;
    char *endptr = 0;

    long val = std::strtol(s.c_str(), &endptr, 10);
    if (endptr == s.c_str() || *endptr != '\0' || errno == ERANGE || val > INT_MAX
        || val <= 0)
        return false;
    out = (int)val;
    return true;
}

void    trim(std::string &str)
{
    if (str.empty())
        return ;
    int i = 0;
    while (str[i] && std::isspace(str[i])) ++i;
    if (!str[i]){
        str = "";
        return ;
    }
    int j = str.length() - 1;
    while (j > 0 && std::isspace(str[j])) --j;
    str = str.substr(i, j - i + 1);
}

void     PmergeMe::parse( char **av )
{
	size_t i = 1;
    for (; av[i] ; ++i)
    {
        std::string a = av[i];
        trim(a);
        int num = 0;
        if (!toIntSafe(a, num))
            errorAndExit();
        nums_v.push_back(num);
        nums_d.push_back(num);
    }
}

void	PmergeMe::errorAndExit( void )
{
	std::cerr << "Error" << std::endl;
	std::exit(1);
}

void	PmergeMe::sort_vec( std::vector<int> &nums )
{
	if (nums.size() <= 1)
		return ;
	std::vector<std::pair<int, int> >	pairs;
	int		Straggler = -1;
	bool	hasStraggler = nums.size() % 2;
	size_t	end = (hasStraggler ? nums.size() - 1: nums.size());
	for (size_t	i = 0;i < end; i += 2)
	{
		if (nums[i] >= nums[i + 1])
			pairs.push_back(std::make_pair(nums[i], nums[i + 1]));
		else
			pairs.push_back(std::make_pair(nums[i + 1], nums[i]));
	}
	if (hasStraggler)
		Straggler = nums[nums.size() - 1];
	std::vector<int> main;
	for (size_t i = 0; i != pairs.size(); ++i)
		main.push_back((pairs[i]).first);

	sort_vec(main);

	// creating pending

	std::vector<int> pend;
	for (size_t i = 0; i < main.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (main[i] == pairs[j].first)
			{
				pend.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}
	if (hasStraggler)
		pend.push_back(Straggler);

	// inserting
	main.insert(main.begin(), pend[0]);
	size_t jsthal[] = {
		1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
		21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203
	};

	size_t n = 0;
	size_t pendingIndex = 1;

	while (pendingIndex < pend.size())
	{
		size_t nextLimit = (jsthal[n + 1] >= pend.size()) ? pend.size() - 1
				: jsthal[n + 1];
		for (size_t i = nextLimit; i >= pendingIndex; --i)
		{
			std::vector<int>::iterator it =
				std::lower_bound(main.begin(), main.end(), pend[i]);
			main.insert(it, pend[i]);
		}
		n++;
		pendingIndex = nextLimit + 1;
	}

	nums = main;
}


void	PmergeMe::sort_deq( std::deque<int> &nums )
{
	if (nums.size() <= 1)
		return ;
	std::deque<std::pair<int, int> >	pairs;
	int		Straggler = -1;
	bool	hasStraggler = nums.size() % 2;
	size_t	end = (hasStraggler ? nums.size() - 1: nums.size());
	for (size_t	i = 0;i < end; i += 2)
	{
		if (nums[i] >= nums[i + 1])
			pairs.push_back(std::make_pair(nums[i], nums[i + 1]));
		else
			pairs.push_back(std::make_pair(nums[i + 1], nums[i]));
	}
	if (hasStraggler)
		Straggler = nums[nums.size() - 1];
	std::deque<int> main;
	for (size_t i = 0; i != pairs.size(); ++i)
		main.push_back((pairs[i]).first);

	sort_deq(main);

	// creating pending

	std::deque<int> pend;
	for (size_t i = 0; i < main.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (main[i] == pairs[j].first)
			{
				pend.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}
	if (hasStraggler)
		pend.push_back(Straggler);

	// inserting
	main.insert(main.begin(), pend[0]);
	size_t jsthal[] = {
		1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
		21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203
	};

	size_t n = 0;
	size_t pendingIndex = 1;

	while (pendingIndex < pend.size())
	{
		size_t nextLimit = (jsthal[n + 1] >= pend.size()) ? pend.size() - 1
				: jsthal[n + 1];
		for (size_t i = nextLimit; i >= pendingIndex; --i)
		{
			std::deque<int>::iterator it =
				std::lower_bound(main.begin(), main.end(), pend[i]);
			main.insert(it, pend[i]);
		}
		n++;
		pendingIndex = nextLimit + 1;
	}

	nums = main;
}