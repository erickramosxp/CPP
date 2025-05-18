#pragma once

#include <iostream>
# include <fstream>
# include <cstring>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

    private:

        std::string _target;

    public:

        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreation);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &shrubberyCreation);

        ShrubberyCreationForm(std::string target);
        void execute(Bureaucrat const & executor) const;
};