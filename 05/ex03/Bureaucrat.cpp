#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Unknown"), grade(150) {

    std::cout << "Default constructor of Bureaucrat was called" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat): name(bureaucrat.name), grade(bureaucrat.grade) {

    std::cout << "Copy constructor of Bureaucrat was called" << std::endl;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat) {

    std::cout << "Copy assignment operator of Bureaucrat was called" << std::endl;

    if (this != &bureaucrat) {
        this->grade = bureaucrat.grade;
    }
    
    return *this;
};

Bureaucrat::~Bureaucrat() {

    std::cout << "Destructor of Bureaucrat " << this->name << " was called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade) {

    std::cout << "Constructor of Bureaucrat was called" << std::endl;

    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat) {

    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";

    return os;
};

std::string Bureaucrat::getName() const {
    return this->name;
};

int Bureaucrat::getGrade() const {
    return this->grade;
};

void Bureaucrat::incrementGrade() { 
    
    if ((grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    
    this->grade--;
};

void Bureaucrat::decrementGrade() {
    
    if ((grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    
    this->grade++;
};

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    
    return "Grade is too high (minimum: 1)";
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    
    return "Grade is too low (max: 150)";
};

void Bureaucrat::signForm(AForm &form) {

    try {

        form.beSigned(*this);

        std::cout << this->getName() << " signed " << form.getName() << std::endl;

    } catch (std::exception& e) {

        std::cerr << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }

};

void Bureaucrat::executeForm(AForm const & form) {

    try {

        std::cout << this->getName() << " trying to execute " << form.getName() << std::endl;

        form.execute(*this);
        
        std::cout << this->getName() << " executed " << form.getName() << std::endl;

    } catch (std::exception& e) {

        std::cerr << this->getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
};