#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class AMateria;

struct Gcollecter
{
    AMateria *address;
    struct Gcollecter* next;
    Gcollecter(): address(0), next(0) {}
};

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
        Gcollecter *Gc;
    public:
        Character();
        Character(std::string name);
        virtual ~Character();
        Character(const Character& other);
        Character&    operator=(const Character& other);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif