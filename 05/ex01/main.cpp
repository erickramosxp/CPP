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

        // Bob tenta assinar TaxForm (grade 50 vs. necessário 30) - falha
        bob.signForm(taxForm);

        // Alice tenta assinar TaxForm (grade 10 vs. necessário 30) - sucesso
        alice.signForm(taxForm);

        // Bob tenta assinar HealthForm (grade 50 vs. necessário 10) - falha
        bob.signForm(healthForm);

        // Alice tenta assinar HealthForm (grade 10 vs. necessário 10) - sucesso
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