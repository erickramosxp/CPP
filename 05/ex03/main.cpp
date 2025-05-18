#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
 
    {
        Intern someRandomIntern;

        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        if (rrf) {
            std::cout << *rrf << std::endl;
            std::cout << dynamic_cast<RobotomyRequestForm*>(rrf)->getTarget() << std::endl;
        }
        
        delete rrf;

        rrf = someRandomIntern.makeForm("shrubbery creation", "Other");

        delete rrf;
    }


    return 0;
}