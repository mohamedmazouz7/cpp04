#include "AMateria.hpp"

AMateria::AMateria() : type("unknown") {}


AMateria::AMateria(std::string const & type) : type(type) {}


AMateria::AMateria(const AMateria& src)
{
    *this = src;
}

AMateria& AMateria::operator = (const AMateria& src)
{
    if (this != &src)
    {
        this->type = src.type;
    }
    return (*this);
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
    return (type);
}

// Virtual use method (can be overridden)
void AMateria::use(ICharacter& target)
{
    std::cout << "* uses " << this->type << " on " << target.getName() << " *\n";
}