#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    void        announce( void );
    void        SetName( std::string name );
    std::string	GetName( void );
    ~Zombie();
    Zombie();
    Zombie(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif