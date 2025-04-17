#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "Creating source and learning Materia:\n";

    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\nCreating characters:\n";

    ICharacter *me = new Character("Gandalf");
    ICharacter *bob = new Character("Bob");

    std::cout << "\nCreating Materia from source:\n";

    AMateria *tmp1 = src->createMateria("icee");
    AMateria *tmp2 = src->createMateria("cure");

    me->equip(tmp1);
    std::cout << "suuuuuu" << std::endl;
    me->equip(tmp2);

    std::cout << "\nUsing equipped Materia:\n";

    me->use(0, *bob); // Ice
    me->use(1, *bob); // Cure

    std::cout << "\nUnequipping one Materia:\n";

    me->unequip(0); // still responsible for deleting tmp1 manually
    delete tmp1;

    std::cout << "\nCleaning up:\n";

    delete me;
    delete bob;
    delete src;
    // delete tmp2; // this was equipped but not unequipped, so we delete it manually

    return 0;
}