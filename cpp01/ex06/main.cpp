#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    Harl harl;
    int i = harl.GetLevel(av[1]);
    switch (i)
    {
        case 0:
            harl.debug();
        case 1:
            harl.info();
        case 2:
            harl.warning();
        case 3:
        {
            harl.error();
            break ;
        }
    
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}