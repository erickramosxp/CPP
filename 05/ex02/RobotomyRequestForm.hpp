#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

    private:

        std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        void initializeSeed() const;

        RobotomyRequestForm(std::string target);
        void execute(Bureaucrat const & executor) const;
};