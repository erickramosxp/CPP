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
        struct Pair
        {
            int smaller;
            int bigger;
        };
        std::vector<Pair> vectorNumbersP;
        static size_t comparisonCount;
        
    public:
    
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        void initContainers(char** args);
        void mergeInsertionSort();
        std::vector<int> sort(std::vector<int>& vector);
        void binaryInsert(std::vector<int>& vector, int number);
        void addCountComparation(int n = 1);
        void printTotalComparison();
        size_t estimateFordJohnsonComparisons(size_t n);

        class InvalidNumberException : public std::exception {

            public:
                const char* what() const throw();
        };
};