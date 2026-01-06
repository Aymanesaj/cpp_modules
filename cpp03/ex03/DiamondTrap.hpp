#ifndef DIAMONTRAP_HPP
#define DIAMONTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;
public:
    DiamondTrap();
    DiamondTrap(std::string newname);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap&    operator=(const DiamondTrap& other);
    ~DiamondTrap();
    void    attack(std::string target);
    void whoAmI();
};

#endif