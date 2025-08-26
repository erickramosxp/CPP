#include <stdexcept>

#include "Span.hpp"

Span::Span(const unsigned int& n): n(n) {};

void Span::addNumber(int nb) {

    if (this->box.size() < this->n) {

        this->box.push_back(nb);
    } else {
        throw std::runtime_error("Limit in vector was achieved");
    }
};

int Span::shortestSpan() {

    // Jogar exceção se estiver vazio ou somente um

    if (this->box.size() <= 1) {
        throw StorageTooLowException();
    }

    int shortestSpan;

    std::sort(this->box.begin(), this->box.end());
    shortestSpan = box.at(box.size() - 1) - box.at(0);
    for (std::vector<int>::iterator it = this->box.begin(); it != this->box.end() - 1; ++it) {

        if ((*(it + 1) - *it) < shortestSpan) {
            shortestSpan = (*(it + 1) - *it);
        }
    }

    return shortestSpan;
};

int Span::longestSpan() {

    // Jogar exceção se estiver vazio ou somente um

    if (this->box.size() <= 1) {
        throw StorageTooLowException();
    }

    int minVal = *std::min_element(this->box.begin(), this->box.end());
    int maxVal = *std::max_element(this->box.begin(), this->box.end());

    return maxVal - minVal;
};

Span::Span(const Span& other) {

    *this = other;
};

Span& Span::operator=(const Span& other) {
    
    if (this != &other) {
        this->n = other.n;
        this->box = other.box;
    }

    return *this;
};

const char* Span::StorageTooLowException::what() const throw() {

    return "Quantity of numbers stored in the span class is too low.";
}

Span::~Span() {

};
