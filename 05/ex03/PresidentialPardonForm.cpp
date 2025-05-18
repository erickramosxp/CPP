#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5) {

    std::cout << "Default constructor of PresidentialPardonForm was called" << std::endl;

    this->_target = "Unknow";
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm("PresidentialPardonForm", 25, 5) {

    std::cout << "Copy constructor of PresidentialPardonForm was called" << std::endl;

    this->_target = other._target;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {


    std::cout << "Copy assignment operator of PresidentialPardonForm was called" << std::endl;

    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }

    return *this;

};

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Destructor of PresidentialPardonForm was called" << std::endl;
};


PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5) {
    
    std::cout << "Constructor of PresidentialPardonForm was called" << std::endl;

    this->_target = target;

};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {

    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    if (this->getGradeToExecute() < executor.getGrade())
        throw AForm::GradeTooLowException();

    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;

};