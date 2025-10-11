#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <exception>

class PmergeMe {

    private:

        std::vector<int> vectorNumbers;
        std::deque<int> dequeNumbers;
    public:
    
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void initContainers(char** args);
        ~PmergeMe();

        class InvalidNumberException : public std::exception {

            public:
                const char* what() const throw();
        };
};