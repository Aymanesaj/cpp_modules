#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    operator=(other);
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other){
        DB = other.DB;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(char *infile)
{
    std::ifstream database("data.csv");
	if (!database.is_open()){
        throw std::runtime_error("Error: could not open database file.");
	}
	std::ifstream input(infile);
	if (!input.is_open()){
        throw std::runtime_error("Error: could not open file.");
	}
    LoadDatabase(database);
	ValidateInput(input);
}

void BitcoinExchange::LoadDatabase(std::ifstream &data)
{
	std::string	line;
	
	std::getline(data, line);
	while (std::getline(data, line))
	{
		std::stringstream ss(line) ;
		std::string date;
		std::string price;
		if (!std::getline(ss, date, ',')) continue;
		if (!std::getline(ss, price)) continue;
		char *endptr;
		float rate = std::strtof(price.c_str(), &endptr);
		DB[date] = rate;
	}
}

float	BitcoinExchange::ValidRate(std::string &value)
{
	errno = 0;
	char *endptr = NULL;
	boost::trim(value);
	float rate = std::strtof(value.c_str(), &endptr);
	if (*endptr != '\0' || endptr == value.c_str())
		std::cout << "Error: bad input => " << line << std::endl;
	else if (rate < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (errno == ERANGE || rate > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else
		return (rate);
	return (-1);
}

int		BitcoinExchange::ft_atoi(std::string& num)
{
	errno = 0;
	char *endptr = NULL;
	boost::trim(num);
	long rate = std::strtol(num.c_str(), &endptr, 10);
	if (*endptr != '\0' || endptr == num.c_str() || errno == ERANGE || rate > std::numeric_limits<int>::max()
		|| rate < 0)
		return (-1);
	return (rate);
}

bool	BitcoinExchange::isValidDate(std::string &date)
{
	boost::trim(date);
	int	count = std::count(date.begin(), date.end(), '-');
	if (count != 2)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (false);
	}
	std::stringstream	date_ss(date);
	std::string			year_str;
	std::string			month_str;
	std::string			day_str;
	std::getline(date_ss, year_str, '-');
	std::getline(date_ss, month_str, '-');
	std::getline(date_ss, day_str);
	int	year = ft_atoi(year_str) - 1900;
	int	month = ft_atoi(month_str) - 1;
	int	day = ft_atoi(day_str);
	if (year < 0 || day < 0 || month < 0 || year > 2026 - 1900)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (false);
	}
	std::tm time_in = {};
	time_in.tm_year = year;
	time_in.tm_mon = month;
	time_in.tm_mday = day;
	time_in.tm_isdst = -1;
	time_t tm = std::mktime(&time_in);
	if (tm == -1 || year != time_in.tm_year
		|| day != time_in.tm_mday || month != time_in.tm_mon)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::ValidateInput(std::ifstream &input)
{
	std::getline(input, line);
	std::string date;
	std::string value;
	while (std::getline(input, line))
	{
		std::stringstream ss(line);
		int count = std::count(line.begin(), line.end(), '|');
		if (count != 1){
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::getline(ss, date, '|');
		std::getline(ss, value);
		if (!isValidDate(date))
			continue;
		float rate = ValidRate(value);
		if (rate < 0)
			continue;
		std::map<std::string, float>::iterator result = DB.lower_bound(date);
		if (result != DB.end() && date != result->first && result == DB.begin()){
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (result == DB.end() || date != result->first)
			--result;
		std::cout << date << " => " << value << " = "
			<< result->second * rate << std::endl;
	}
}
