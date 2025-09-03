#include "HumanA.hpp"

class HumanB
{
private:
    Weapon      *weapon;
    std::string name;
public:
    HumanB(std::string Name);
    void        setWeapon( Weapon &newWeapon);
    void        attack( void );
    std::string getName();
    const std::string& getWeaponType();
};
