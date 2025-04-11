#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat Default constructor is called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src)
{
    std::cout << "Cat copy constructor is called 🐱" << std::endl;
    this->brain = new Brain(*src.brain);
    *this = src;
}

Cat& Cat::operator=(const Cat& src)
{
    std::cout << "Cat Copy assignment operator is called 🐱" << std::endl;
    if (this != &src)
    {
        Animal::operator=(src);
        if (brain)
            delete brain;
        this->brain = new Brain(*src.brain);
    }
    return *this;
}

void Cat::makeSound() const 
{
    std::cout << this->type <<  " Meow! 🐱" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
    if (brain)
        brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    if (brain)
        return brain->getIdea(index);
    return "";
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destroyed 🐱" << std::endl;
}