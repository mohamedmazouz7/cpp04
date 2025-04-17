#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
    public:
        Character();
        Character(std::string const& name);
        Character(const Character& src);
        Character& operator = (const Character& src);
        ~Character();
    
        std::string const &getName() const;
        AMateria* getMateria(int idx) const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);

};

#endif