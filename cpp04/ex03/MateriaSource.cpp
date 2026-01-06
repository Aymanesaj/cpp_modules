#include "MateriaSource.hpp"

MateriaSource::MateriaSource() { for (int i = 0; i < 4; i++) inventory[i] = 0; }

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++) if (inventory[i]) inventory[i] = 0;
    for (int i = 0; i < 4; i++) if (other.inventory[i]) inventory[i] = other.inventory[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other){
        for (int i = 0; i < 4; i++) if (inventory[i]) { delete inventory[i]; inventory[i] = 0; }
        for (int i = 0; i < 4; i++) if (other.inventory[i]) inventory[i] = other.inventory[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++) if (inventory[i]) { delete inventory[i]; }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i] && materia)
        {
            inventory[i] = materia;
            return ;
        }
    }
}

AMateria*    MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] && inventory[i]->getType() == type)
        {
            return (inventory[i]->clone());
        }
    }
    return (0);
}