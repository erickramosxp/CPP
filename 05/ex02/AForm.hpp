#pragma once

#include <iostream>

class Bureaucrat;

class AForm {

    private:

        const std::string name;
        bool signedForm;
        int gradeToSign;
        int gradeToExecute;

    public:

        AForm();
        AForm(const AForm &form);
        AForm& operator=(const AForm &form);
        ~AForm();

        AForm(std::string name, int gradeToSign, int gradeToExecute);
        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void setSigned();
        void setGradeToSign(int gradeToSign);
        void setGradeToExecute(int gradeToExecute);

        void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception {

            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &os, const AForm& form);