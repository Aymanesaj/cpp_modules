#include "Weapon.hpp"

class HumanA
{
private:
    Weapon      &weapon;
    std::string name;
public:
    HumanA(std::string Name, Weapon& Weapon);
    void        attack( void );
    std::string getName();
    const std::string& getWeaponType();
};
