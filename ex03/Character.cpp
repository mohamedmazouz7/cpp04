#include "Character.hpp"

Character::Character() : name("default")
{
    std::cout << "Character default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
    std::cout << "Character std::string constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character &src) : name(src.name)
{
    std::cout << "Character Copy constructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (src.inventory[i])
            inventory[i] = src.inventory[i];
        else
            inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &src)
{
    std::cout << "Character copy assignement oprator" << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i];
            if (src.inventory[i])
                inventory[i] = src.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return (*this);
}

std::string const &Character::getName() const
{
    // std::cout << "Character getName" << std::endl; 
    return (this->name);
}

void Character::equip(AMateria *m)
{
    std::cout << "Character equip" << std::endl; 
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    std::cout << "Character unequip" << std::endl; 
    if (idx >= 0 && idx < 4)
    {
        inventory[idx] = NULL;        
    }
}

void Character::use(int idx, ICharacter &target)
{
    std::cout << "Character use" << std::endl; 
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
      inventory[idx]->use(target); 
    }
}

AMateria* Character::getMateria(int idx) const
{
    if (idx >= 0 && idx < 4)
        return inventory[idx];
    return NULL;
}

Character::~Character()
{
    std::cout << "Character destructor" << std::endl; 
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
}