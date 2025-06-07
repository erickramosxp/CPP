#pragma once

#include <iostream>
#include <cctype>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

    private:

    public:

        Intern();
        Intern(const Intern &other);
        Intern& operator=(const Intern &other);
        ~Intern();
        AForm* makeForm(std::string nameForm, std::string targetOfForm);
        bool compareIgnoreCase(const std::string &first, const std::string &second);

        class InvalidFormException : public std::exception {
            public:

                const char* what() const throw();
        };
};