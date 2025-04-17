#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        stor_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    std::cout << "MateriaSource: copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (src.stor_materia[i])
            stor_materia[i] = src.stor_materia[i]->clone();
        else
            stor_materia[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    std::cout << "MateriaSource: copy assignment called" << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            if (stor_materia[i])
                delete stor_materia[i];
            if (src.stor_materia[i])
                stor_materia[i] = src.stor_materia[i]->clone();
            else
                stor_materia[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource: destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (stor_materia[i])
            delete stor_materia[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    std::cout << "MateriaSource: learnMateria called" << std::endl;
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!stor_materia[i])
        {
            stor_materia[i] = m->clone(); // 👈 clone it! Ice or Cure because clone is on Amateria class
            delete m;
            return;
        }
    }
} 

AMateria* MateriaSource::createMateria(std::string const& type)
{
    std::cout << "MateriaSource: createMateria called with type = " << type << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (stor_materia[i] && stor_materia[i]->getType() == type)
            return stor_materia[i]->clone();
    }
    return NULL;
}
