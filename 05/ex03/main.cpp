#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
 
    {
        Intern someRandomIntern;

        AForm* rrf;

        try {
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");

            if (rrf) {
                std::cout << *rrf << std::endl;
                std::cout << dynamic_cast<RobotomyRequestForm*>(rrf)->getTarget() << std::endl;
            }
        } catch (std::exception& ex) {
            std::cout << "Cannot make this " << ex.what() << std::endl;
        }
        if (rrf)
            delete rrf;
        
        rrf = NULL;
        try {
            
            rrf = someRandomIntern.makeForm("shrubbery creationasd", "Other");

        } catch (std::exception& ex) {
            std::cout << "Cannot make this " << ex.what() << std::endl;
        }
        if (rrf)
            delete rrf;
    }


    return 0;
}