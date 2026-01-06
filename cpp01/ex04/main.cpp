#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

void    print_error( void )
{
    std::cerr << "Error\n";
    std::exit(1);
}

std::string my_replace(const std::string& str, size_t pos, size_t len, const std::string& replacement){
    if (pos > str.size())
        return str;
    std::string result = str.substr(0, pos);
    result += replacement;
    if (pos + len < str.size())
        result += str.substr(pos + len);
    return (result);
}

void CopyFile(std::ifstream& infile, std::ofstream& outfile, char **av)
{
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string text;


    std::stringstream buffer;
    buffer << infile.rdbuf();
    text = buffer.str();
    std::size_t pos = 0;
    while (s1 != "" && s1 != s2 && ((pos = text.find(s1, pos)) != std::string::npos))
    {
        text = my_replace(text, pos, s1.length(), s2);
        pos += s2.length();
    }
    outfile << text;
}

int main(int ac, char **av)
{
    if (ac != 4)
        print_error();
    std::string     filename = av[1];
    std::ifstream   infile(filename.c_str());
    if (!infile.is_open())
        print_error();
    std::ofstream   outfile((filename + ".replace").c_str());
    if (!outfile.is_open())
        print_error();
    CopyFile(infile, outfile, av);
}
