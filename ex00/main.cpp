#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << "-------------- This is WrongAnimal Test ----------------" << std::endl;
    const WrongAnimal* wrong_animal = new WrongAnimal();
    const WrongAnimal* worngcat = new WrongCat();
    std::cout << wrong_animal->getType() << std::endl;
    std::cout << worngcat->getType() << std::endl;
    worngcat->makeSound();
    delete wrong_animal;
    delete worngcat;
    return 0;
}
