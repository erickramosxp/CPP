#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Default constructor of Intern was called" << std::endl;
};

Intern::Intern(const Intern&) {
    std::cout << "Copy constructor was called" << std::endl;
};

Intern& Intern::operator=(const Intern&) {
    std::cout << "Copy assigment of Intern was called" << std::endl;

    return *this;
};

Intern::~Intern() {
    std::cout << "Destructor of Intern was called" << std::endl;
};

bool Intern::compareIgnoreCase(const std::string &first, const std::string &second) {

    if (first.length() != second.length())
        return (false);

    for(std::string::size_type i = 0; i < first.length(); i++) {

        if (std::tolower(first[i]) != std::tolower(second[i]))
            return (false);
    }

    return (true);
}

const char* Intern::InvalidFormException::what() const throw(){
    return "Type form invalid.";
}

AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(std::string formName, std::string targetOfForm) {
    
    struct Forms {
        std::string name;
        AForm* (*create)(const std::string&);
    };
    
    Forms forms[] = {
        {"shrubbery creation", &createShrubbery},
        {"robotomy request", &createRobotomy},
        {"presidential pardon", &createPresidential}
    };

    for (int i = 0; i < 3; ++i) {
        if (forms[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(targetOfForm);
        };
    };
    
    // std::cout << "Invalid option form" << std::endl;
    throw Intern::InvalidFormException();

    return NULL;
};
