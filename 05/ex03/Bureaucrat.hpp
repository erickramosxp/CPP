#pragma once

#include <iostream>
#include "AForm.hpp"

class Bureaucrat {

    private:
        const std::string name;
        int grade;

    public:

        Bureaucrat();
        Bureaucrat(const Bureaucrat &bureaucrat);
        Bureaucrat& operator=(const Bureaucrat &bureaucrat);
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);
        void executeForm(AForm const & form);
        
        class GradeTooHighException : public std::exception {
            
            public:
                const char* what() const throw();
            };
            
        class GradeTooLowException : public std::exception {
                
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat);