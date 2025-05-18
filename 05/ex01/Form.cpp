#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Unknow"), signedForm(false), gradeToSign(1), gradeToExecute(1) {

    std::cout << "Default constructor of Form was called" << std::endl;
};

Form::Form(const Form &form) {

    std::cout << "Copy constructor of Form was called" << std::endl;

    *this = form;
};

Form& Form::operator=(const Form &form) {

    std::cout << "Copy assignment operator of Form was called" << std::endl;

    if (this != &form) {

        this->signedForm = form.signedForm;
        this->gradeToSign = form.gradeToSign;
        this->gradeToExecute = form.gradeToExecute;
    }

    return *this;
};

Form::~Form() {

    std::cout << "Destructor of Form was called" << std::endl;
};

std::ostream& operator<<(std::ostream &os, const Form& form) {

    os << "Name form: " << form.getName() << ", this form " << (form.getSigned() ? " was " : " wasn't") << " signed, " << "Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute();

    return os;
};

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), signedForm(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {

    std::cout << "Constructor of Form was called" << std::endl;

    if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1)
        throw Form::GradeTooHighException();
    else if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150)
        throw Form::GradeTooLowException();
};

std::string Form::getName() const {
    
    return this->name;
};

bool Form::getSigned() const {

    return this->signedForm;
};

int Form::getGradeToSign() const {

    return this->gradeToSign;
};
int Form::getGradeToExecute() const {

    return this->gradeToExecute;
};

const char* Form::GradeTooHighException::what() const throw() {
    
    return "Grade is too high for sign form";
};

const char* Form::GradeTooLowException::what() const throw() {
    
    return "Grade is too low for sign form";
};

void Form::beSigned(Bureaucrat &bureaucrat) {

    std::cout << bureaucrat.getName() << " is trying to sign the form \"" << this->getName() << "\"..." << std::endl;

    if (this->getGradeToSign() < bureaucrat.getGrade())
        throw Form::GradeTooLowException();
    
    this->signedForm = true;
};