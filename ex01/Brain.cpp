#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        ideas[i] = "";
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = src.ideas[i];
}

Brain&  Brain::operator = (const Brain& src)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = src.ideas[i];
    }
    return (*this);
}

void  Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (ideas[index]);
    return "";
}

Brain::~Brain()
{
    std::cout << "Brain destructor called 🧠" << std::endl;
}