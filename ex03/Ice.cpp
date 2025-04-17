#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}


Ice::Ice(const Ice& src) : AMateria(src)
{
    *this = src;
}

Ice& Ice::operator=(const Ice& src)
{
    if (this != &src)
    {
        this->type = src.type;
    }
    return (*this);
}

Ice::~Ice()
{
}

// Clone (returns a new instance of Ice)
AMateria* Ice::clone() const
{
    return new Ice(*this);
}

// Use
void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}