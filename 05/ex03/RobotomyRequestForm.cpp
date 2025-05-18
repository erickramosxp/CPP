#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) {
    
    std::cout << "Default constructor of RobotomyRequestForm was called" << std::endl;
    
    this->_target = "Unknow";
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm("RobotomyRequestForm", 72, 45) {

    std::cout << "Copy constructor of RobotomyRequestForm was called" << std::endl;
    this->_target = other._target;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {


    std::cout << "Copy assignment operator of RobotomyRequestForm was called" << std::endl;

    if (this != &other) {
        
        AForm::operator=(other);
        this->_target = other._target;
    }

    return *this;
};

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Destructor of RobotomyRequestForm was called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45) {

    std::cout << "Constructor of RobotomyRequestForm was called" << std::endl;

    this->_target = target;
};

std::string RobotomyRequestForm::getTarget() const {
    
    return this->_target;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

    
    if (!this->getSigned())
    throw AForm::FormNotSignedException();
    if (this->getGradeToExecute() < executor.getGrade())
    throw AForm::GradeTooLowException();

    std::cout << "BZZZZZZZZZZZT...ZRRRRRRRRRRR...! [some drilling noises]" << std::endl;

    std::srand(std::time(0));
    if (std::rand() % 2 == 0)
        std::cout << this->_target << " has been successfully robotomized!" << std::endl;
    else
        std::cout << "The robotomy of " << _target << " has failed." << std::endl;
    
};