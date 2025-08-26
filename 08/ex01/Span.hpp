#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

class Span {

    private:

        unsigned int n;
        std::vector<int> box;
        Span();

    public:

        Span(const unsigned int& n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        void addNumber(int nb);
        int shortestSpan();
        int longestSpan();
        ~Span();

        template<typename Iterator>
        void addRange(Iterator begin, Iterator end);

        class StorageTooLowException: public std::exception {
            
            public:

                const char * what() const throw();
        };
};

template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {

    while (begin != end) {

        if (box.size() >= this->n) {
            throw std::runtime_error("Span is full while adding range");
        }
        box.push_back(*begin);
        begin++;
    }
};