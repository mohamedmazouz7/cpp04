<div align="center">

# 🔮 CPP Module 04

**Subtype polymorphism, abstract classes, and interfaces — The power of virtual functions.**

![C++](https://img.shields.io/badge/language-C%2B%2B98-orange?style=for-the-badge&logo=cplusplus)
![42](https://img.shields.io/badge/school-42-black?style=for-the-badge)
![Score](https://img.shields.io/badge/score-100%2F100-brightgreen?style=for-the-badge)

</div>

---

## 🧠 Concepts Covered

- **Virtual functions** — Enable polymorphic behavior through dynamic dispatch
- **Virtual destructors** — Ensure proper cleanup in inheritance hierarchies
- **Polymorphism** — Different derived classes, same interface
- **Abstract classes** — Pure virtual functions, cannot be instantiated
- **Interfaces** — Pure abstract classes defining contracts
- **Deep vs shallow copying** — Proper resource management in inheritance
- **Pointer-based polymorphism** — Using base class pointers to derived objects

---

## 📁 Exercises

| Ex | Name | Main Topics |
|----|------|------------|
| `ex00` | Polymorphism | Virtual functions, correct/wrong polymorphism examples |
| `ex01` | I don't want to set the world on fire | Brain class, deep copying, destructors in hierarchy |
| `ex02` | Abstract class | Pure virtual functions, uninstantiable base class |
| `ex03` | Interface & recap | Complete system: Materia, Character, MateriaSource |

---

## 🚀 Build & Run

```bash
cd ex00      # (or ex01, ex02, ex03)
make
./program_name
```

---

## 💡 Key Learnings

### ex00 — Polymorphism
Implement base class **Animal** with virtual `makeSound()`:
- **Dog** and **Cat** override `makeSound()`
- **WrongAnimal** and **WrongCat** show what happens **without** virtual functions
- Key insight: Virtual functions enable correct polymorphic behavior

```cpp
const Animal* j = new Dog();
j->makeSound();  // Calls Dog::makeSound(), not Animal::makeSound()
```

### ex01 — Brain & Deep Copying
Add **Brain** class with 100 ideas:
- **Dog** and **Cat** own a `Brain*` (allocated with `new`)
- Test **deep copying** — copies must have their own Brain, not share
- Proper cleanup chain: Animal destructors called in reverse order

```cpp
Animal* animals[10];
// First 5: Dogs, Last 5: Cats
delete j;  // Virtual destructor ensures Dog/Cat cleanup, then Animal
```

### ex02 — Abstract Classes
Make **Animal** uninstantiable:
- Add pure virtual function: `virtual void makeSound() const = 0;`
- No `Animal` objects can be created
- Dog/Cat implementations required
- Prevents nonsensical base class instantiation

### ex03 — Interfaces & Complete System
Build a Final Fantasy-style spell system:

**AMateria** (abstract base):
- Pure virtual: `clone()`, `use()`
- Concrete: **Ice**, **Cure** classes

**ICharacter** (interface):
- Pure virtual interface for characters
- **Character** implementation with 4-slot inventory
- `equip()`, `unequip()`, `use()` methods

**IMateriaSource** (interface):
- Stores "template" Materias
- `learnMateria()` — Remember a Materia type
- `createMateria()` — Clone learned Materia by type

---

## 🎯 Core Concept: Virtual Functions

### Without Virtual (Wrong):
```cpp
class Animal { public: void makeSound() { ... } };
class Cat : public Animal { public: void makeSound() { ... } };

Animal* ptr = new Cat();
ptr->makeSound();  // Calls Animal::makeSound() ❌ WRONG!
```

### With Virtual (Correct):
```cpp
class Animal { public: virtual void makeSound() { ... } };
class Cat : public Animal { public: virtual void makeSound() { ... } };

Animal* ptr = new Cat();
ptr->makeSound();  // Calls Cat::makeSound() ✅ CORRECT!
```

The compiler resolves the function call **at runtime** based on the actual object type.

---

## 🔐 Abstract Classes

Pure virtual function makes class uninstantiable:

```cpp
class Animal {
public:
    virtual ~Animal() {}
    virtual void makeSound() const = 0;  // = 0 means pure virtual
};

// This will NOT compile:
// Animal a;  // Error: cannot instantiate abstract class

// But this works:
Animal* ptr = new Dog();  // Dog implements makeSound()
```

---

## 🎮 Materia System (ex03)

```
IMateriaSource
├── learnMateria(AMateria*)     // Store template
└── createMateria(std::string)  // Clone by type

AMateria
├── Ice (shoots ice bolt)
└── Cure (heals wounds)

ICharacter
└── Character (4-slot inventory)
    ├── equip(AMateria*)
    ├── unequip(int)
    └── use(int, ICharacter&)
```

Example usage:
```cpp
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());

AMateria* ice = src->createMateria("ice");   // Clone of learned Ice
ICharacter* player = new Character("Hero");
player->equip(ice);
player->use(0, *enemy);  // Shoots ice bolt at enemy
```

---

## 📝 Deep Copy Example

```cpp
Dog dog1("Buddy");
Dog dog2 = dog1;  // Deep copy

dog2.addIdea("woof");  // Only dog2's Brain affected
// dog1's Brain is unchanged
```

vs Shallow copy (WRONG):
```cpp
// Without proper copying:
Dog dog1, dog2;
dog2.brain = dog1.brain;  // Same pointer!
// Both share the same Brain — dangerous!
```

---

## ⚡ Key Principles

✅ **Always use virtual destructors** in base classes  
✅ **Use pure virtual functions** to define contracts  
✅ **Implement deep copying** for pointer members  
✅ **Delete via base class** — virtual destructors ensure proper cleanup  
✅ **Use interfaces** to define abstract contracts  
✅ **Test polymorphic behavior** — verify virtual resolution works  

---

<div align="center">

*Polymorphism: The art of writing once, executing many ways.*

*Part of the 42 School C++ curriculum.*

</div>
