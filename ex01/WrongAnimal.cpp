#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal:: WrongAnimal(const WrongAnimal& src)
{
    *this = src;
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& src)
{
    std::cout << "WrongAnimal Copy assignment operator is called" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
    }
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound 🤪" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}