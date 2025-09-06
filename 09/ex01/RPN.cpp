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

RPN::RPN(const std::string& input) {

    if (input.empty()) {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
    std::istringstream istream(input);

    std::string symbol;
    while (std::getline(istream, symbol, ' ')) {

        if (!symbol.compare(" ") || symbol.empty()) {
            continue ;
        }

        if (!isOperator(symbol) && !validNumber(symbol)) {
            std::cout << "This is no valid input '" <<  symbol << "'" << std::endl;
            return ;
        }
        if ((symbol.size() > 1 && symbol.at(0) != '-')) {
            std::cout << "This input is not available in the program '" << symbol << "'" << std::endl;
            return ;
        }

        if (!isOperator(symbol)) {
            int index = symbol.at(0) == '-' ? 1 : 0;
            inputNumbers.push((symbol.at(index) - '0'));
        } else if (inputNumbers.empty()) {
            std::cout << "Order of element is not valid." << std::endl;
            return ;
        } else {

            int nb1 = inputNumbers.top();
            inputNumbers.pop();

            if (inputNumbers.empty()) {
                std::cout << "Order of element is not valid." << std::endl;
                return ;
            }
            int nb2 = inputNumbers.top();
            inputNumbers.pop();

            int newNumber;

            if (!symbol.compare("*")) {
                newNumber = nb1 * nb2;
            }  else if (!symbol.compare("/")) {
                if (nb1 == 0) {
                    std::cout << "Error: zero division" << std::endl;
                    return ;
                }
                std::cout << nb2 << " " << nb1 << std::endl;
                newNumber = nb2 / nb1;
            } else if (!symbol.compare("+")) {
                newNumber = nb2 + nb1;
            } else if (!symbol.compare("-")) {
                newNumber = nb2 - nb1;
            }
            inputNumbers.push(newNumber);
        }
    }

    if (inputNumbers.size() > 1) {
        std::cout << "Error in the input program" << std::endl;
    } else {
        std::cout << inputNumbers.top() << std::endl;
    }

};