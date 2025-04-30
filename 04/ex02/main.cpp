#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {

    std::cout << "\n=== Creating Animals ===\n" << std::endl;

    std::cout << "Creating a Dog..." << std::endl;
    const Animal* dog = new Dog();
    std::cout << "-> Dog address: " << dog << std::endl;
    std::cout << "-> Calling makeSound(): " << std::endl;
    dog->makeSound();

    std::cout << "\nCreating a Cat..." << std::endl;
    const Animal* cat = new Cat();
    std::cout << "-> Cat address: " << cat << std::endl;
    std::cout << "-> Calling makeSound(): " << std::endl;
    cat->makeSound();

    std::cout << "\n=== Destroying Animals ===\n" << std::endl;
    std::cout << "Deleting Dog..." << std::endl;
    delete dog;

    std::cout << "\nDeleting Cat..." << std::endl;
    delete cat;

    // Test for NOT instantiation of Animal
    // const Animal* animal = new Animal();

    return 0;
}