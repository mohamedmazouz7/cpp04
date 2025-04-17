#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* stor_materia[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& src);
        MateriaSource& operator = (const MateriaSource& src);
        ~MateriaSource();

        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const& type);
};

#endif