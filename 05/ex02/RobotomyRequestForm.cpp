#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <sstream>

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

void RobotomyRequestForm::initializeSeed() const {

    const void* ptr = &this->_target;

    std::ostringstream oss;
    oss << ptr;

    std::string ptr_str = oss.str();
    if (ptr_str.substr(0, 2) == "0x")
        ptr_str = ptr_str.substr(2);

    unsigned long addrs = std::strtoul(ptr_str.c_str(), NULL, 16);
    std::srand(std::time(0) + addrs);
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

    
    if (!this->getSigned())
    throw AForm::FormNotSignedException();
    if (this->getGradeToExecute() < executor.getGrade())
    throw AForm::GradeTooLowException();

    std::cout << "BZZZZZZZZZZZT...ZRRRRRRRRRRR...! [some drilling noises]" << std::endl;

    this->initializeSeed();
    if (std::rand() % 2 == 0)
        std::cout << this->_target << " has been successfully robotomized!" << std::endl;
    else
        std::cout << "The robotomy of " << _target << " has failed." << std::endl;
};