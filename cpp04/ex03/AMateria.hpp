#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class ICharacter;

#include <iostream>
#include "Character.hpp"

class AMateria
{
protected:
    std::string type;
public:
    AMateria();
    virtual ~AMateria();
    AMateria(const AMateria& other);
    AMateria(std::string const & type);
    AMateria&    operator=(const AMateria& other);
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif