#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon();
    Weapon(std::string newType);
    const std::string& getType( void );
    void  setType( const std::string& newType );
};
