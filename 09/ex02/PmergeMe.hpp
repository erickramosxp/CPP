#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <cstddef>
#include <climits>
#include <exception>
#include <iomanip>
#include <algorithm>
#include <sys/time.h>

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
        std::deque<Pair> dequeNumbersP;

        long long timeElepsedVector;
        long long timeElepsedDeque;
        
    public:
    
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void initContainers(char** args);
        std::vector<int> jacobsthalSequence(size_t n);
        std::vector<int> generateJacobsthalInsertionOrder(size_t n);


        int validNumber(std::string arg);
        bool isInteger(std::string arg);
        bool isNumber(std::string arg);
        long long getTime();

        template <typename Container>
        void printVector(Container& vector);
        template <typename Container>
        void printPair(std::vector<Pair> pairs);
        template <typename Container>
        bool isSorted(Container& container);


        template <typename Container>
        bool isLessThanTwo(Container& container);
        template <typename Container>
        void moveIfSizeIsOdd(Container& smallestNumbers, Container& container);
        template <typename ContainerPair, typename Container>
        void separateLargerAndSmaller(ContainerPair& pairs, Container& smallestNumbers, Container& largestNumbers, Container& container);
        template <typename ContainerPair, typename Container>
        int findSmallerPairPositionForFirstLargest(ContainerPair& pairs, Container& smallestNumbers, Container& largestNumbers);
        template <typename Container>
        void insertFirstSmallerOfFirstPair(Container& smallestNumbers, Container& largestNumbers, const size_t& smallerPosition);
        template <typename ContainerPair, typename Container>
        int findBiggerPair(const ContainerPair& pairs, const Container& maiores, int number);
        template <typename Container>
        void binaryInsert(Container& vector, int number, size_t maxSize);
        template <typename ContainerPair, typename Container>
        void insertAllPendingSmallers(ContainerPair& pairs, Container& smallestNumbers, Container& largestNumbers);
        
        void mergeInsertionSort();
        void runSortDeque();
        void runSortVector();
        void printTimeElepsed();
        void verifyIsSorted();
        std::vector<int> sortVector(std::vector<int>& container);
        std::deque<int> sortDeque(std::deque<int>& container);


        class InvalidNumberException : public std::exception {

            public:
                const char* what() const throw();
        };
};

template <typename Container>
void PmergeMe::printPair(std::vector<Pair> pairs) {


    std::cout << "Pairs: ";
    for (size_t i = 0; i < pairs.size(); i++) {

        std::cout << "[" << pairs[i].smaller << ", " << pairs[i].bigger << "]";
    }
    std::cout << std::endl;
}


template <typename Container>
void PmergeMe::printVector(Container& vector) {

    typename Container::iterator vectorIterator = vector.begin();
    
    while (vectorIterator != vector.end()) {
        std::cout << *vectorIterator << " ";
        ++vectorIterator;
    }
    std::cout << std::endl;
}

template <typename Container>
bool PmergeMe::isSorted(Container& container) {

    size_t end = container.size() - 1;

    for (size_t i = 0; i < end; i++) {
        if (container[i] > container[i + 1])
            return (false);
    }
    return (true);
}

template <typename Container>
bool PmergeMe::isLessThanTwo(Container& container) {

    if (container.size() <= 1)
        return (true);

    if (container.size() == 2) {
        if (container[0] > container[1]) {
            std::swap(container[0], container[1]);
        }
        return (true);
    }
    return (false);
}

template <typename Container>
void PmergeMe::moveIfSizeIsOdd(Container& smallestNumbers, Container& container) {

    if (container.size() % 2 != 0) {
        int last = container.back();
        container.pop_back();
        smallestNumbers.push_back(last);
    }
}

template <typename ContainerPair, typename Container>
void PmergeMe::separateLargerAndSmaller(ContainerPair& pairs, Container& smallestNumbers, Container& largestNumbers, Container& container) {

    typedef typename Container::iterator iterator;
    iterator it = container.begin();

    while (it != container.end()) {
        
        iterator first = it++;
        iterator second = it++;
        Pair p;

        if (*first < *second) {
            p.bigger = *second;
            p.smaller = *first;
        } else {
            p.bigger = *first;
            p.smaller = *second;
        }
        smallestNumbers.push_back(p.smaller);
        largestNumbers.push_back(p.bigger);
        pairs.push_back(p);
    }
}

template <typename ContainerPair, typename Container>
int PmergeMe::findSmallerPairPositionForFirstLargest(ContainerPair& pairs, Container& smallestNumbers, Container& largestNumbers) {

    size_t i = 0;
    for (; i < pairs.size(); i++) {
        if (pairs[i].bigger == largestNumbers[0]) {
            break ;
        }
    }
    
    size_t j = 0;

    for (; j < smallestNumbers.size(); j++) {
        if (smallestNumbers[j] == pairs[i].smaller)
            break ;
    }

    return j;
}

template <typename Container>
void PmergeMe::insertFirstSmallerOfFirstPair(Container& smallestNumbers, Container& largestNumbers, const size_t& smallerPosition) {

    largestNumbers.insert(largestNumbers.begin(), smallestNumbers[smallerPosition]);
    smallestNumbers.erase(smallestNumbers.begin() + smallerPosition);
}

template <typename ContainerPair, typename Container>
int PmergeMe::findBiggerPair(const ContainerPair& pairs, const Container& maiores, int number) {

    for (size_t i = 0; i < pairs.size(); i++) {

        if (pairs[i].smaller == number) {

            for (size_t j = 0; j < maiores.size(); j++) {
                if (maiores[j] == pairs[i].bigger)
                    return j;
            }
        }
    }

    return maiores.size();
}

template <typename Container>
void PmergeMe::binaryInsert(Container& vector, int number, size_t maxSize) {

    size_t end = (maxSize);
    size_t start = 0;

    while (start < end)
    {
        size_t middle = start + (end - start) / 2;

        if (number < vector[middle]) {
            end = middle;
        } else {
            start = middle + 1;
        }
        
    }
    vector.insert(vector.begin() + start, number);
}

template <typename ContainerPair, typename Container>
void PmergeMe::insertAllPendingSmallers(ContainerPair& pairs, Container& smallestNumbers, Container& largestNumbers) {

    std::vector<int> insertionOrder = generateJacobsthalInsertionOrder(smallestNumbers.size());

    for (size_t i = 0; i < smallestNumbers.size(); i++)
    {
        int pairBigger = findBiggerPair(pairs, largestNumbers, smallestNumbers[insertionOrder[i]]);
        binaryInsert(largestNumbers, smallestNumbers[insertionOrder[i]], pairBigger);
    }
}
