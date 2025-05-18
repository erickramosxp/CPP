#include "Bureaucrat.hpp"

int main() {

    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade();  
        std::cout << b1 << std::endl;

        b1.incrementGrade();  
    } catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;

        b2.decrementGrade();
        std::cout << b2 << std::endl;

        b2.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Carlos", 0);
    } catch (const std::exception& e) {
        std::cerr << "Error creating Carlos: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Diana", 151);
    } catch (const std::exception& e) {
        std::cerr << "Error creating Diana: " << e.what() << std::endl;
    }

    return 0;
}
