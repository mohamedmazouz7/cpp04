#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
    *this = src;
    std::cout << "WrongCat copy constructor callded" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& src)
{
    std::cout << "WrongCat Copy assignment operator is called" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
    }
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound (meow?) 🐱❌" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed" << std::endl;
}