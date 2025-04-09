#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat Default constructor is called" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
    *this = src;
    std::cout << "Cat copy constructor is called 🐱" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
    std::cout << "Cat Copy assignment operator is called 🐱" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
    }
    return *this;
}

void Cat::makeSound() const 
{
    std::cout << this->type <<  " Meow! 🐱" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed 🐱" << std::endl;
}