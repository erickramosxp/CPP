#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Constructors and Polymorphism Test ===\n" << std::endl;

    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n[Types]" << std::endl;
    std::cout << "dog is a " << dog->getType() << std::endl;
    std::cout << "cat is a " << cat->getType() << std::endl;

    std::cout << "\n[Sounds - via base class pointer]" << std::endl;
    cat->makeSound(); // Cat sound
    dog->makeSound(); // Dog sound
    meta->makeSound(); // Animal sound

    std::cout << "\n=== WrongAnimal Polymorphism Test ===" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\n[Wrong Sounds - via base class pointer]" << std::endl;
    wrongAnimal->makeSound(); // WrongAnimal sound
    wrongCat->makeSound();    // WrongAnimal sound again, if not virtual

    std::cout << "\n=== Direct Use of Derived Classes ===" << std::endl;
    Dog realDog;
    Cat realCat;
    WrongCat realWrongCat;

    std::cout << "\n=== Sounds use of Derived Classes ===" << std::endl;
    realDog.makeSound();
    realCat.makeSound();
    realWrongCat.makeSound();

    std::cout << "\n=== Copy Constructor and Assignment Operator ===" << std::endl;
    Dog copyDog(realDog);
    Cat assignedCat;
    assignedCat = realCat;

    std::cout << "\n=== Cleanup (destructors) ===" << std::endl;
    delete meta;
    delete dog;
    delete cat;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
