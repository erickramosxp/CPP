#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Unknow"), signedForm(false), gradeToSign(1), gradeToExecute(1) {

    std::cout << "Default constructor of Form was called" << std::endl;
};

AForm::AForm(const AForm &form) {

    std::cout << "Copy constructor of Form was called" << std::endl;

    *this = form;
};

AForm& AForm::operator=(const AForm &form) {

    std::cout << "Copy assignment operator of Form was called" << std::endl;

    if (this != &form) {

        this->signedForm = form.signedForm;
        this->gradeToSign = form.gradeToSign;
        this->gradeToExecute = form.gradeToExecute;
    }

    return *this;
};

AForm::~AForm() {

    std::cout << "Destructor of Form was called" << std::endl;
};

std::ostream& operator<<(std::ostream &os, const AForm& form) {

    os << "Name form: " << form.getName() << ", this form " << (form.getSigned() ? " was " : " wasn't") << " signed, " << "Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute();

    return os;
};

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), signedForm(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {

    std::cout << "Constructor of Form was called" << std::endl;

    if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1)
        throw AForm::GradeTooHighException();
    else if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150)
        throw AForm::GradeTooLowException();
};

std::string AForm::getName() const {
    
    return this->name;
};

bool AForm::getSigned() const {

    return this->signedForm;
};

int AForm::getGradeToSign() const {

    return this->gradeToSign;
};
int AForm::getGradeToExecute() const {

    return this->gradeToExecute;
};

void AForm::setSigned() {

    this->signedForm = true;
};

void AForm::setGradeToSign(int gradeToSign) {

    this->gradeToSign = gradeToSign;
};
void AForm::setGradeToExecute(int gradeToExecute) {

    this->gradeToExecute = gradeToExecute;
};

const char* AForm::GradeTooHighException::what() const throw() {
    
    return "Grade is too high";
};

const char* AForm::GradeTooLowException::what() const throw() {
    
    return "Grade is too low";
};

const char* AForm::FormNotSignedException::what() const throw() {
    
    return "Form not signed";
};

void AForm::beSigned(Bureaucrat &bureaucrat) {

    std::cout << bureaucrat.getName() << " is trying to sign the form \"" << this->getName() << "\"..." << std::endl;

    if (this->getGradeToSign() < bureaucrat.getGrade())
        throw AForm::GradeTooLowException();
    
    this->signedForm = true;

    std::cout << bureaucrat.getName() << " successfully signed the form \"" << this->getName() << "\"." << std::endl;
};