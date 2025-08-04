#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

class Span {

    private:

        unsigned int n;
        std::vector<int> box;

    public:

        Span(const unsigned int& n);
        void addNumber(int nb);
        int shortestSpan();
        int longestSpan();
};