#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {

        Bureaucrat bob("Bob", 72);
        Bureaucrat alice("Alice", 44);
        Bureaucrat alexandre("Alexandre de Morais", 2);

        ShrubberyCreationForm shrubberyForHome("Home");

        RobotomyRequestForm robotomyForMarvin("Marvin");

        PresidentialPardonForm pardonForKennedy("John Kennedy");

        std::cout << "============ Forms before signing ============" << std::endl;
        
        std::cout << shrubberyForHome << std::endl;
        std::cout << robotomyForMarvin << std::endl;
        std::cout << pardonForKennedy << std::endl;
        
        std::cout << "---------- Signing ShrubberyCreationForm ----------" << std::endl;
        bob.signForm(shrubberyForHome);
        std::cout << "---------- Signing RobotomyRequestForm ----------" << std::endl;
        bob.signForm(robotomyForMarvin);
        // Bob tenta assinar HealthForm (grade 50 vs. necessário 10) - falha
        std::cout << "---------- Signing PresidentialPardonForm ----------" << std::endl;
        alexandre.signForm(pardonForKennedy);
        
        std::cout << "---------- Processing ShrubberyCreationForm ----------" << std::endl;
        alice.executeForm(shrubberyForHome);
        std::cout << "---------- Processing RobotomyRequestForm ----------" << std::endl;
        alice.executeForm(robotomyForMarvin);
        std::cout << "---------- Processing PresidentialPardonForm ----------" << std::endl;
        alexandre.executeForm(pardonForKennedy);
        
        std::cout << "============ Forms after signing ============" << std::endl;
        
        std::cout << shrubberyForHome << std::endl;
        std::cout << robotomyForMarvin << std::endl;
        std::cout << pardonForKennedy << std::endl;


    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}