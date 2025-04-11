#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog Default constructor is called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src)
{
    std::cout << "Dog copy constructor is called 🐶" << std::endl;
    this->brain = new Brain(*src.brain);
}

Dog& Dog::operator=(const Dog& src)
{
    std::cout << "Dog Copy assignment operator is called 🐶" << std::endl;
    if (this != &src)
    {
        Animal::operator=(src);
        if (brain)
            delete brain;
        brain = new Brain(*src.brain);
    }
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << this->type <<" is braking 🐶" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
    if (brain)
        brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    if (brain)
        return brain->getIdea(index);
    return "";
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destroyed 🐶" << std::endl;
}