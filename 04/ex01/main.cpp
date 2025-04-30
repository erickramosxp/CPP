#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Basic Allocation Test ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j; // Deve chamar ~Dog e ~Brain
    delete i; // Deve chamar ~Cat e ~Brain

    std::cout << "\n=== Array of Animals Test ===" << std::endl;
    const int size = 4;
    Animal* animals[size];

    for (int index = 0; index < size; ++index) {
        if (index < size / 2)
            animals[index] = new Dog();
        else
            animals[index] = new Cat();
    }

    for (int index = 0; index < size; ++index) {
        delete animals[index]; // Deve chamar os destrutores corretos
    }

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog original;
    original.setIdea(0, "Chase the cat");
    original.setIdea(1, "Eat bones");

    Dog copy = original; // Deve chamar o copy constructor com deep copy

    std::cout << "Original idea 0: " << original.getIdea(0) << std::endl;
    std::cout << "Copy idea 0: " << copy.getIdea(0) << std::endl;

    // Modifica o copy e mostra que o original não muda
    copy.setIdea(0, "Sleep all day");

    std::cout << "After modifying copy:" << std::endl;
    std::cout << "Original idea 0: " << original.getIdea(0) << std::endl;
    std::cout << "Copy idea 0: " << copy.getIdea(0) << std::endl;

    return 0;
}
