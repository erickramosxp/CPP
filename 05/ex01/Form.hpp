#pragma once

#include <iostream>

class Bureaucrat;

class Form {

    private:

        const std::string name;
        bool signedForm;
        int gradeToSign;
        int gradeToExecute;

    public:

        Form();
        Form(const Form &form);
        Form& operator=(const Form &form);
        ~Form();

        Form(std::string name, int gradeToSign, int gradeToExecute);
        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception {

            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &os, const Form& form);