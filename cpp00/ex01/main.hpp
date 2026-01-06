#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

/* UI User Interface namespace */
namespace UI
{
	void	DisplayColumns(std::string	str);
	bool	IsNumber(const std::string& s);
	void ReadLineOrExit(std::string &out);
};

#endif