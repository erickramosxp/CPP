#include "RPN.hpp"
#include <sstream>
#include <cctype>

RPN::RPN(const RPN& other) {

    *this = other;
};

RPN& RPN::operator=(const RPN& other) {

    if (this != &other) {

        this->inputNumbers = other.inputNumbers;
    }

    return *this;
};

RPN::~RPN() {

};

bool isOperator(const std::string& op) {

    if (!op.compare("*") || !op.compare("/") || !op.compare("+") || !op.compare("-")) {
        return true;
    }
    return false;
}

bool validNumber(const std::string& number) {

    size_t i = 0;

    if (number.at(0) == '-')
        i++;
    for (; i < number.size(); i++) {
        if (!std::isdigit(number.at(i))) {
            return false;
        }
    }
    return true;
}

int multiply(int a, int b) {
 return (a * b);
}

int divide(int a, int b) {
    
    // Jogar exceção quando for divisão por zero
    if (b == 0) {
        std::cout << "Error: zero division" << std::endl;
        return 0;
    }
    return (a / b);
}

int add(int a, int b) {
    return (a + b);
}

int subtract(int a, int b) {
    return (a - b);
}

void RPN::inicializationListOfOperations() {
    
    listOperations[0].operation = ADD;
    listOperations[0].func = &add;
    listOperations[1].operation = SUB;
    listOperations[1].func = &subtract;
    listOperations[2].operation = MUL;
    listOperations[2].func = &multiply;
    listOperations[3].operation = DIV;
    listOperations[3].func =  &divide;
};

int validateInput(const std::string& symbol) {

    
    // Jogar uma exceção

    if (!isOperator(symbol) && !validNumber(symbol)) {
        std::cout << "This is no valid input '" <<  symbol << "'" << std::endl;
        return (0);
    }
    if ((symbol.size() > 1 && symbol.at(0) != '-') || (symbol.size() > 2 && symbol.at(0) == '-')) {
        std::cout << "This input is not available in the program '" << symbol << "'" << std::endl;
        return (0);
    }
    return (1);
};

int RPN::handlerInput(const std::string& symbol) {

    int nb1 = 0;
    int nb2 = 0;

    if (!isOperator(symbol)) {
        int index = symbol.at(0) == '-' ? 1 : 0;
        int number = index == 1 ? ((symbol.at(index) - '0') * -1):(symbol.at(index) - '0');
        inputNumbers.push(number);
    } else if (inputNumbers.empty()) {
        // Jogar exceção
        std::cout << "Order of element is not valid." << std::endl;
        return 0;
    } else {
        
        nb1 = inputNumbers.top();
        inputNumbers.pop();
        if (inputNumbers.empty()) {
            // Jogar exceção
            std::cout << "Order of element is not valid." << std::endl;
            return 0;
        }
        nb2 = inputNumbers.top();
        inputNumbers.pop();
        int newNumber = 0;
        for(int i = 0; i < 4; i++) {
            if (symbol[0] == listOperations[i].operation) {
                newNumber = listOperations[i].func(nb2, nb1);
                break ;
            }
        }
        inputNumbers.push(newNumber);
    }
    return 1;
}

RPN::RPN(const std::string& input) {

    if (input.empty()) {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
    inicializationListOfOperations();

    std::istringstream istream(input);
    std::string symbol;
    while (std::getline(istream, symbol, ' ')) {

        if (!symbol.compare(" ") || symbol.empty()) {
            continue ;
        }
        if (!validateInput(symbol))
            return ;
        if (!handlerInput(symbol)) {
            return ;
        };
    }

    if (inputNumbers.size() > 1) {
        std::cout << "Error in the input program" << std::endl;
    } else {
        std::cout << inputNumbers.top() << std::endl;
    }

}