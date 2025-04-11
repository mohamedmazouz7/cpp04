#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat& src);
        Cat& operator = (const Cat& src);
        void makeSound() const;
        ~Cat();

        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

#endif