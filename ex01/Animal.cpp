#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
    
}

Animal::Animal(const Animal& src)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal& Animal::operator = (const Animal& src)
{
    std::cout << "Animal Copy assignment operator is called" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
    }
    return(*this);
}

void    Animal::makeSound() const
{
    std::cout << "Some generic animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}

Animal::~Animal()
{
    std::cout << "Animal destroyed 🪦" << std::endl;
}
