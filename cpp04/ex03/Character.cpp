#include "Character.hpp"

Character::Character(): Gc(0) { for (int i = 0; i < 4; i++) inventory[i] = 0; }

Character::Character(std::string name):name(name), Gc(0) { for (int i = 0; i < 4; i++) inventory[i] = 0; }

Character::~Character()
{
    for (int i = 0; i < 4; i++) if (inventory[i]) { delete inventory[i]; }
    Gcollecter* tmp = Gc;
    Gcollecter* next = Gc;
    while (tmp) {
        next = next->next;
        delete tmp->address;
        delete tmp;
        tmp = next;
    }
}

Character::Character(const Character& other)
{
    name = other.name;
    for (int i = 0; i < 4; i++) inventory[i] = 0;
    for (int i = 0; i < 4; i++) if (other.inventory[i]) inventory[i] = other.inventory[i]->clone();
}

Character&    Character::operator=(const Character& other)
{
    if (this != &other){
        name = other.name;
        for (int i = 0; i < 4; i++) if (inventory[i]) { delete inventory[i]; inventory[i] = 0; }
        for (int i = 0; i < 4; i++) if (other.inventory[i]) inventory[i] = other.inventory[i]->clone();
    }
    return (*this);
}

std::string const & Character::getName() const { return (name); }

void Character::equip(AMateria* m)
{
    if (!m) return ;
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return ;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    Gcollecter *tmp;
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        if (!Gc)
        {
            Gc = new Gcollecter;
            tmp = Gc;
            tmp->address = inventory[idx];
            tmp->next = 0;
        }
        else
        {
            tmp = Gc;
            for (; tmp && tmp->next ;tmp = tmp->next);
            tmp->next = new Gcollecter;
            tmp->next->address = inventory[idx];
            tmp->next->next = 0;
        }
        inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}
