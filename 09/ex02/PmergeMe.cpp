#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe& other) {

    this->vectorNumbers = other.vectorNumbers;
    this->dequeNumbers = other.dequeNumbers;
};

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    
    if (this != &other) {
        this->vectorNumbers = other.vectorNumbers;
        this->dequeNumbers = other.dequeNumbers;
    }
    return *this;
};

PmergeMe::~PmergeMe() {

  //  std::cout << "Destructor was called." << std::endl;
};

bool isNumber(std::string arg) {

    for (int i = 0; arg[i]; i++) {
        if (!std::isdigit(arg[i]))
            return (false);
    }
    return (true);
}

bool isInteger(std::string arg) {

    if (arg.find('.', 0) != std::string::npos) {
        return (false);
    }
    return (true);
}

int validNumber(std::string arg) {

    if (!isInteger(arg)) {
        throw PmergeMe::InvalidNumberException();
    }
    if (!isNumber(arg)) {
        throw PmergeMe::InvalidNumberException();
    }
    int number = std::atoi(arg.c_str());
    return (number);
}

void PmergeMe::initContainers(char** args) {


    for (int i = 0; args[i] ; i++)
    {
        // if (!isInteger(args[i])) {
        //     std::cout << args[i] << " not is an integer" << std::endl;
        // };
        int number = validNumber(args[i]);
        this->vectorNumbers.push_back(number);
        this->dequeNumbers.push_back(number);
    }
    
    std::vector<int>::iterator vectorIterator = this->vectorNumbers.begin();
    while (vectorIterator != vectorNumbers.end()) {
        std::cout << *vectorIterator << std::endl;
        ++vectorIterator;
    }
};


const char* PmergeMe::InvalidNumberException::what() const throw() {

    return "Invalid number!";
}
