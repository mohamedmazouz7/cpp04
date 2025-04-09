#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog Default constructor is called" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
    *this = src;
    std::cout << "Dog copy constructor is called 🐶" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
    std::cout << "Dog Copy assignment operator is called 🐶" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
    }
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << this->type <<" is braking 🐶" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed 🐶" << std::endl;
}