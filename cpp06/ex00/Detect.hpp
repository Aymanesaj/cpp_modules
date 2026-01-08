#ifndef DETECT_HPP
#define DETECT_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "ScalarConverter.hpp"
#include <limits>
#include <vector>
#include <iomanip>
#include <cfloat>
#include <errno.h>

enum type {c, i, f, d, invalid};

namespace Detect
{
	type	Detectliteral(const std::string &literal);
	bool	isPseudo(const std::string &literal);
	bool	isChar(const std::string &literal);
	bool	isFloat(const std::string &literal);
	bool	isDouble(const std::string &literal);
	bool	isInt(const std::string &literal);
	bool	overflow(const std::string &literal);
	void	print(double value, bool overflow, std::string literal, type type);
}



#endif