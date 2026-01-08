#include "Detect.hpp"

void	Detect::print(double value, bool overflow, std::string literal, type type)
{
	// char
	std::string str = literal;
	if (!str.empty())
		str.erase(str.end() - 1);
	char c = static_cast<char>(value);
	if (overflow || isPseudo(literal) || isPseudo(str) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	// int
	int i = static_cast<int>(value);
	if (overflow || isPseudo(literal) || isPseudo(str))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	// float
	float f = static_cast<float>(value);
	char *end;
	errno = 0;
	value = std::strtod(literal.c_str(), &end);
	if (type != c && (value > FLT_MAX || value == -FLT_MAX) && errno == ERANGE)
	{
		if ((value > FLT_MAX || value == -FLT_MAX) && errno == ERANGE)
			std::cout << "float: impossible" << std::endl;
	}
	else if ((long long)value == value)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	// double
	double d = value;
	errno = 0;
	value = std::strtod(literal.c_str(), &end);
	if (type != c && (value == HUGE_VAL || value == -HUGE_VAL) && errno == ERANGE)
		std::cout << "double: impossible" << std::endl;
	else if ((long long)value == value)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

bool	Detect::overflow(const std::string &literal)
{
	char *endptr;
	errno = 0;
	long l = std::strtol(literal.c_str(), &endptr, 10);
	if (errno == ERANGE || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
		return (true);
	return (false);
}

bool	Detect::isPseudo(const std::string &literal)
{
	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return true;
	return false;
}

bool	Detect::isChar(const std::string &literal)
{
	if (literal.length() == 3 && (literal[0] == '\'' && literal[2] == '\''))
		return true;
	return false;
}

bool	Detect::isFloat(const std::string &literal)
{
	if (literal[0] && literal[literal.length() - 1] == 'f')
	{
		std::string str = literal;
		str.erase(str.end() - 1);
		return (isDouble(str));
	}
	return false;
}

bool	Detect::isDouble(const std::string &literal)
{
	if (isPseudo(literal))
		return (true);
	int index = 0;
	int dot = 0;
	if ((literal[index] == '-' || literal[index] == '+') && literal[index + 1])
		index++;
	if (literal[index] == '.')
		return false;
	while (literal[index])
	{
		if (literal[index] == '.')
		{
			index++;
			dot++;
			continue ;
		}
		if (!std::isdigit(literal[index]))
			return false;
		index++;
	}
	if (dot != 1 || literal[index - 1] == '.')
		return false;
	return true;
}

bool	Detect::isInt(const std::string &literal)
{
	int index = 0;
	if ((literal[index] == '-' || literal[index] == '+') && literal[index + 1])
		index++;
	while (literal[index])
	{
		if (!std::isdigit(literal[index]))
			return false;
		index++;
	}
	return true;
}

type Detect::Detectliteral(const std::string &literal)
{
	bool types[4] = {Detect::isChar(literal), Detect::isInt(literal), Detect::isFloat(literal), Detect::isDouble(literal)};
	int index = 0;
	while (index < 4)
	{
		if (types[index])
			return (type)index;
		index++;
	}
	return invalid;
}
