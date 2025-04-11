#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal& src);
        Animal& operator = (const Animal& src);
        virtual void makeSound() const;
        std::string getType() const;
        virtual ~Animal();
};

#endif