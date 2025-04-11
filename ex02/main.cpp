#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal *j = new Dog();
    // const Animal *b = new Animal();
    std::cout << "suuuu\n";
    // const Animal obj;
    std::cout << "suuuu\n";
    const Animal *i = new Cat();
    delete j;
    delete i;

    std::cout << "=== Deep Copy Test ===" << std::endl;
    {
        Dog original;
        original.setIdea(0, "Play fetch!");
        original.setIdea(1, "Chase the cat!");

        Dog copy = original;

        std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
        std::cout << "Copy idea[0]: " << copy.getIdea(0) << std::endl;

        original.setIdea(0, "Destroy fetch!");

        std::cout << "After changing original..." << std::endl;
        std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
        std::cout << "Copy idea[0]: " << copy.getIdea(0) << std::endl;
    }

    std::cout << "=== Animal Array Test ===" << std::endl;

    // const int SIZE = 4;
    // Animal *animals[SIZE];

    // for (int i = 0; i < SIZE / 2; ++i)
    //     animals[i] = new Dog();
    // for (int i = SIZE / 2; i < SIZE; ++i)
    //     animals[i] = new Cat();

    // for (int i = 0; i < SIZE; ++i)
    //     animals[i]->makeSound();

    // for (int i = 0; i < SIZE; ++i)
    //     delete animals[i];

    return 0;
}