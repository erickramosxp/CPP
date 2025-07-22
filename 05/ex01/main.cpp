#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 10);

        Form taxForm("TaxForm", 30, 20);
        Form healthForm("HealthForm", 10, 5);

        std::cout << taxForm << std::endl;
        std::cout << healthForm << std::endl;

        // Bob trying to sign TaxForm (grade 50 vs. required 30) - fail
        bob.signForm(taxForm);

        // Alice trying to sign TaxForm (grade 10 vs. required 30) - sucess
        alice.signForm(taxForm);

        // Bob trying to sign HealthForm (grade 50 vs. required 10) - fail
        bob.signForm(healthForm);

        // Alice trying to sign HealthForm (grade 10 vs. required 10) - sucess
        alice.signForm(healthForm);

        std::cout << taxForm << std::endl;
        std::cout << healthForm << std::endl;

        // Teste de formulário com grade inválido (muito alto)
        Form invalidFormHigh("InvalidHigh", 0, 10); // Deve lançar exceção

    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Teste de formulário com grade inválido (muito baixo)
        Form invalidFormLow("InvalidLow", 160, 10); // Deve lançar exceção
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}