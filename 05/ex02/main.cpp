#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 138);

        ShrubberyCreationForm healthForm("Home");
        ShrubberyCreationForm taxForm("TaxForm");

        std::cout << healthForm << std::endl;

        // Bob tenta assinar TaxForm (grade 50 vs. necessário 30) - falha
        bob.signForm(taxForm);

        // Bob tenta assinar HealthForm (grade 50 vs. necessário 10) - falha
        bob.signForm(healthForm);


        std::cout << taxForm << std::endl;
        std::cout << healthForm << std::endl;

        alice.executeForm(healthForm);


    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}