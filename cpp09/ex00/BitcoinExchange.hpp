#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <cerrno>
#include <limits>
#include <ctime>
#include <boost/algorithm/string.hpp>

class BitcoinExchange
{
private:
	std::string	line;
	std::map<std::string, float> DB;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	BitcoinExchange(char *infile);
	~BitcoinExchange();
	void	LoadDatabase(std::ifstream &data);
	void	ValidateInput(std::ifstream &input);
	float	ValidRate(std::string &rate);
	bool	isValidDate(std::string &date);
	int		ft_atoi(std::string &num);
};


#endif