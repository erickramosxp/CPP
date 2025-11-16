#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): timeElepsedVector(0), timeElepsedDeque(0) {};

PmergeMe::PmergeMe(const PmergeMe& other) {

    this->vectorNumbers = other.vectorNumbers;
    this->dequeNumbers = other.dequeNumbers;
    timeElepsedDeque = 0;
    timeElepsedVector = 0;
};

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    
    if (this != &other) {
        this->vectorNumbers = other.vectorNumbers;
        this->dequeNumbers = other.dequeNumbers;
    }
    return *this;
};

PmergeMe::~PmergeMe() {

};

bool PmergeMe::isNumber(std::string arg) {

    for (int i = 0; arg[i]; i++) {
        if (!std::isdigit(arg[i]))
            return (false);
    }
    return (true);
}

bool PmergeMe::isInteger(std::string arg) {

    if (arg.find('.', 0) != std::string::npos) {
        return (false);
    }
    return (true);
}


int PmergeMe::validNumber(std::string arg) {

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
        int number = validNumber(args[i]);
        if (std::find(vectorNumbers.begin(), vectorNumbers.end(), number) != this->vectorNumbers.end())
            throw std::runtime_error("Error: duplicate value");
        this->vectorNumbers.push_back(number);
        this->dequeNumbers.push_back(number);
    }
};

long long PmergeMe::getTime() {

    struct timeval time;

    gettimeofday(&time, 0);

    long long timeNow = (time.tv_sec * 1000000LL) + time.tv_usec;

    return (timeNow);
}


std::vector<int> PmergeMe::jacobsthalSequence(size_t n) {

    std::vector<int> seq;
    size_t j1 = 1, j2 = 0;

    seq.push_back(1);
    while (true) {
        size_t next = j1 + 2 * j2;
        if (next >= n)
            break;
        seq.push_back(next);
        j2 = j1;
        j1 = next;
    }
    return seq;
}

std::vector<int> PmergeMe::generateJacobsthalInsertionOrder(size_t n) {

    std::vector<int> order;

    if (n == 0) 
        return order;
    if (n == 1) { 
        order.push_back(0); 
        return order; 
    }

    std::vector<int> jacob = jacobsthalSequence(n);

    size_t prev = 0;
    for (size_t i = 1; i < jacob.size(); ++i) {
        size_t current = jacob[i];
        for (size_t k = current; k > prev; --k)
            order.push_back(k - 1);
        prev = current;
    }

    for (size_t k = n; k > prev; --k)
        order.push_back(k - 1);

    return order;
}

std::vector<int> PmergeMe::sortVector(std::vector<int>& container) {


    if (isLessThanTwo(container))
        return container;

    std::vector<int> smallestNumbers;
    std::vector<int> largestNumbers;
    std::vector<Pair> pairs;
    
    moveIfSizeIsOdd(smallestNumbers, container);
    separateLargerAndSmaller(pairs, smallestNumbers, largestNumbers, container);
    if (largestNumbers.size() > 1) {
        largestNumbers = sortVector(largestNumbers);
    }

    size_t smallerPosition = findSmallerPairPositionForFirstLargest(pairs, smallestNumbers, largestNumbers);
    insertFirstSmallerOfFirstPair(smallestNumbers, largestNumbers, smallerPosition);
    if (smallestNumbers.size() == 0)
        return largestNumbers;
    insertAllPendingSmallers(pairs, smallestNumbers, largestNumbers);
    
    return (largestNumbers);
}


std::deque<int> PmergeMe::sortDeque(std::deque<int>& container) {


    if (isLessThanTwo(container))
        return container;

    std::deque<int> smallestNumbers;
    std::deque<int> largestNumbers;
    std::deque<Pair> pairs;
    
    
    moveIfSizeIsOdd(smallestNumbers, container);
    separateLargerAndSmaller(pairs, smallestNumbers, largestNumbers, container);
    if (largestNumbers.size() > 1) {
        largestNumbers = sortDeque(largestNumbers);
    }

    size_t smallerPosition = findSmallerPairPositionForFirstLargest(pairs, smallestNumbers, largestNumbers);
    insertFirstSmallerOfFirstPair(smallestNumbers, largestNumbers, smallerPosition);
    if (smallestNumbers.size() == 0)
        return largestNumbers;
    insertAllPendingSmallers(pairs, smallestNumbers, largestNumbers);
    
    return (largestNumbers);
}

void PmergeMe::runSortVector() {

    long long initialTime, endTime;

    initialTime = getTime();
    this->vectorNumbers = sortVector(this->vectorNumbers);
    endTime = getTime();

    this->timeElepsedVector = (endTime - initialTime);
}

void PmergeMe::runSortDeque() {

    long long initialTime, endTime;

    initialTime = getTime();
    this->dequeNumbers = sortDeque(this->dequeNumbers);
    endTime = getTime();

    this->timeElepsedDeque = (endTime - initialTime);
}

void PmergeMe::printTimeElepsed() {

    std::cout << "Time to process a range of " << vectorNumbers.size() << " elements with std::vector : " << timeElepsedVector << " us"<< std::endl;
    std::cout << "Time to process a range of " << dequeNumbers.size() << " elements with std::deque : " << timeElepsedDeque << " us"<< std::endl;
}

void PmergeMe::verifyIsSorted() {
    
    if (!isSorted(this->vectorNumbers)) {
        std::cout << "The std::vector container are not sorted" << std::endl;
    }
    if (!isSorted(this->dequeNumbers)) {
        std::cout << "The std::deque container are not sorted" << std::endl;
    }
}

void PmergeMe::mergeInsertionSort() {

    std::cout << "Before: ";
    printVector(vectorNumbers);

    runSortVector();
    runSortDeque();
    
    std::cout << "After: ";
    printVector(vectorNumbers);

    printTimeElepsed();
    verifyIsSorted();
}


const char* PmergeMe::InvalidNumberException::what() const throw() {

    return "Invalid number!";
}
