#include "Detect.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other) {}
	return *this ;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
	type type = Detect::Detectliteral(literal);
	double value;
	char *endptr;
	bool	overflow = false;
	switch (type)
	{
		case c:
		{
			char c = literal[1];
			value = static_cast<double>(c);
			break;
		}
		case i:
		{
			overflow = Detect::overflow(literal);
			int	i = std::atoi(literal.c_str());
			if (!overflow)
				value = static_cast<double>(i);
			else
				value = std::strtod(literal.c_str(), &endptr);
			break;
		}
		case f:
		{
			float f = std::strtod(literal.c_str(), &endptr);
			value = static_cast<double>(f);
			break;
		}
		case d:
			value = std::strtod(literal.c_str(), &endptr);
			break;
		default:
			std::cout << "The type conversion is impossible." << std::endl;
			return;
	}
	Detect::print(value, overflow, literal, type);
}