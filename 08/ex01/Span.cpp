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

    int minVal = *std::min_element(this->box.begin(), this->box.end());
    int maxVal = *std::max_element(this->box.begin(), this->box.end());

    return maxVal - minVal;
};
