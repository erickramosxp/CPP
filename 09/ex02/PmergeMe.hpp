#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <cstddef>
#include <exception>
#include <sys/time.h>
#include <iomanip>

template <typename Container>
class PmergeMe {

    private:

        Container vectorNumbers;
        // std::deque<int> dequeNumbers;
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
        Container sort(Container& vector);
        std::vector<size_t> jacobsthalSequence(size_t n);
        size_t intLog2(size_t n);
        std::vector<size_t> generateJacobsthalInsertionOrder(size_t n);
        int validNumber(std::string arg);
        bool isInteger(std::string arg);
        bool isNumber(std::string arg);
        int findBiggerPair(const std::vector<Pair>& pairs, const Container& maiores, int number);
        void binaryInsert(Container& vector, int number, size_t maxSize);
        void binaryInsert(std::vector<int>& vector, int number);
        void addCountComparation(int n = 1);
        void printTotalComparison();
        void printVector(Container& vector);
        size_t estimateFordJohnsonComparisons(size_t n);
        size_t fordJohnsonComparisons(size_t n);
        void printPair(std::vector<Pair> pairs);

        inline unsigned long long now_us();
        inline unsigned long long now_ms();
        inline void print_human_time_us(unsigned long long us);

        class InvalidNumberException : public std::exception {

            public:
                const char* what() const throw();
        };
};

template <typename Container>
inline unsigned long long PmergeMe<Container>::now_us() {
    timeval tv; gettimeofday(&tv, 0);
    return (unsigned long long)tv.tv_sec * 1000000ULL +
           (unsigned long long)tv.tv_usec;
}

template <typename Container>
inline unsigned long long PmergeMe<Container>::now_ms() {
    return now_us() / 1000ULL;
}

template <typename Container>
inline void PmergeMe<Container>::print_human_time_us(unsigned long long us) {
    // Mostre us; se ficar grande, mostre ms com 3 casas
    std::cout << "Time to process a range of 5 elements with std ";
    if (us >= 1000ULL) {
        std::cout.setf(std::ios::fixed);
        std::cout << std::setprecision(3) << (us / 1000.0) << " ms";
    } else {
        std::cout << us << " us";
    }
    std::cout << std::endl;
}

template <typename Container>
size_t PmergeMe<Container>::comparisonCount = 0;

template <typename Container>
PmergeMe<Container>::PmergeMe() {};

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container>& other) {

    this->vectorNumbers = other.vectorNumbers;
    // this->dequeNumbers = other.dequeNumbers;
};

template <typename Container>
std::vector<size_t> PmergeMe<Container>::generateJacobsthalInsertionOrder(size_t n) {
    std::vector<size_t> order;
    if (n == 0) return order;
    if (n == 1) { order.push_back(0); return order; }

    // --- gera sequência Jacobsthal pura ---
    std::vector<size_t> jacob;
    jacob.push_back(1);
    size_t j1 = 1, j2 = 0;
    while (true) {
        size_t next = j1 + 2 * j2;
        if (next >= n)
            break;
        jacob.push_back(next);
        j2 = j1;
        j1 = next;
    }

    // --- monta ordem de inserção ---
    size_t prev = 0; // começa em 0 para cobrir o primeiro bloco
    for (size_t i = 0; i < jacob.size(); ++i) {
        size_t current = jacob[i];
        for (size_t k = current; k > prev; --k)
            order.push_back(k - 1); // -1 p/ converter p/ base 0
        prev = current;
    }

    // --- adiciona o bloco final ---
    for (size_t k = n; k > prev; --k)
        order.push_back(k - 1);

    return order;
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe<Container>& other) {
    
    if (this != &other) {
        this->vectorNumbers = other.vectorNumbers;
        // this->dequeNumbers = other.dequeNumbers;
    }
    return *this;
};

template <typename Container>
PmergeMe<Container>::~PmergeMe() {

  //  std::cout << "Destructor was called." << std::endl;
};

template <typename Container>
void PmergeMe<Container>::addCountComparation(int n) {
    PmergeMe::comparisonCount += n;
};
template <typename Container>
void PmergeMe<Container>::printTotalComparison() {

    std::cout << "Total de comparações: " << PmergeMe::comparisonCount << std::endl;
};

template <typename Container>
bool PmergeMe<Container>::isNumber(std::string arg) {

    for (int i = 0; arg[i]; i++) {
        if (!std::isdigit(arg[i]))
            return (false);
    }
    return (true);
}

template <typename Container>
bool PmergeMe<Container>::isInteger(std::string arg) {

    if (arg.find('.', 0) != std::string::npos) {
        return (false);
    }
    return (true);
}

template <typename Container>
int PmergeMe<Container>::validNumber(std::string arg) {

    if (!isInteger(arg)) {
        throw PmergeMe::InvalidNumberException();
    }
    if (!isNumber(arg)) {
        throw PmergeMe::InvalidNumberException();
    }
    int number = std::atoi(arg.c_str());
    return (number);
}

template <typename Container>
size_t PmergeMe<Container>::intLog2(size_t n) {
    size_t log = 0;
    while (n >>= 1)
        ++log;
    return log;
}

template <typename Container>
std::vector<size_t> PmergeMe<Container>::jacobsthalSequence(size_t n) {
    std::vector<size_t> seq;
    seq.push_back(1);
    size_t j1 = 1, j2 = 0;
    while (true) {
        size_t next = j1 + 2 * j2;
        if (next > n)
            break;
        seq.push_back(next);
        j2 = j1;
        j1 = next;
    }
    return seq;
}

template <typename Container>
size_t PmergeMe<Container>::fordJohnsonComparisons(size_t n) {
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;

    size_t pairs = n / 2;
    size_t rest = (n + 1) / 2; // ceil(n/2)
    size_t total = pairs;      // comparações iniciais para formar pares

    // recursão nos "maiores"
    total += fordJohnsonComparisons(rest);

    // sequência de inserções Jacobsthal
    std::vector<size_t> seq = jacobsthalSequence(pairs);
    std::vector<bool> inserted(pairs, false);
    size_t insertedCount = 0;

    for (size_t i = 0; i < seq.size(); ++i) {
        size_t index = seq[i];
        if (index > pairs)
            index = pairs;
        while (insertedCount < index) {
            ++insertedCount;
            // custo de inserir um elemento com busca binária no vetor atual
            total += intLog2(rest + insertedCount);
        }
    }

    return total;
}

template <typename Container>
size_t PmergeMe<Container>::estimateFordJohnsonComparisons(size_t n) {
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;

    size_t pairs = n / 2;
    size_t rest = (n + 1) / 2; // ceil(n/2)

    // 1️⃣ Comparações iniciais para formar pares
    size_t comparisons = pairs;

    // 2️⃣ Recursão nos "maiores"
    comparisons += estimateFordJohnsonComparisons(rest);

    // 3️⃣ Inserções binárias dos "menores"
    for (size_t inserted = 1; inserted < pairs; ++inserted)
        comparisons += intLog2(inserted + 1);

    // 4️⃣ Compensa o elemento ímpar solitário (se existir)
    if (n % 2 != 0)
        comparisons += 1;

    return comparisons;
}

template <typename Container>
void PmergeMe<Container>::initContainers(char** args) {


    for (int i = 0; args[i] ; i++)
    {
        // if (!isInteger(args[i])) {
        //     std::cout << args[i] << " not is an integer" << std::endl;
        // };
        int number = validNumber(args[i]);
        this->vectorNumbers.push_back(number);
        // this->dequeNumbers.push_back(number);
    }
    
    // std::vector<int>::iterator vectorIterator = this->vectorNumbers.begin();
    // while (vectorIterator != vectorNumbers.end()) {
    //     std::cout << *vectorIterator << std::endl;
    //     ++vectorIterator;
    // }
};

template <typename Container>
void PmergeMe<Container>::printPair(std::vector<Pair> pairs) {


    std::cout << "Pares: ";
    for (size_t i = 0; i < pairs.size(); i++) {

        std::cout << "[" << pairs[i].smaller << ", " << pairs[i].bigger << "]";
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe<Container>::mergeInsertionSort() {


    unsigned long long start = now_us();
// ... seu código ...
// std::cout << "Total de comparações estimadas " << fordJohnsonComparisons(this->vectorNumbers.size()) << std::endl;
    this->vectorNumbers = sort(this->vectorNumbers);
    printVector(vectorNumbers);
    unsigned long long elapsed = now_us() - start;
    print_human_time_us(elapsed);
    // std::cout << "Elapsed: " << elapsed << " us\n";
    // printTotalComparison();
}

template <typename Container>
const char* PmergeMe<Container>::InvalidNumberException::what() const throw() {

    return "Invalid number!";
}

// template <typename Container>
// void PmergeMe::initContainers(char** args) {


//     for (int i = 0; args[i] ; i++)
//     {
//         // if (!isInteger(args[i])) {
//         //     std::cout << args[i] << " not is an integer" << std::endl;
//         // };
//         int number = validNumber(args[i]);
//         this->vectorNumbers.push_back(number);
//         // this->dequeNumbers.push_back(number);
//     }
    
//     // std::vector<int>::iterator vectorIterator = this->vectorNumbers.begin();
//     // while (vectorIterator != vectorNumbers.end()) {
//     //     std::cout << *vectorIterator << std::endl;
//     //     ++vectorIterator;
//     // }
// };



// gera a sequência de Jacobsthal até n
// std::vector<size_t> jacobsthalSequence(size_t n) {
    
//     std::vector<size_t> seq;
//     seq.push_back(1);
//     size_t j1 = 1, j2 = 0;
//     while (true) {
//         size_t next = j1 + 2 * j2;
//         if (next > n)
//             break;
//         seq.push_back(next);
//         j2 = j1;
//         j1 = next;
//     }
//     return seq;
// }

// simulação exata do número de comparações do Ford–Johnson
// size_t PmergeMe::fordJohnsonComparisons(size_t n) {
//     if (n <= 1)
//         return 0;
//     if (n == 2)
//         return 1;

//     size_t pairs = n / 2;
//     size_t rest = (n + 1) / 2; // ceil(n/2)
//     size_t total = pairs;      // comparações iniciais para formar pares

//     // recursão nos "maiores"
//     total += fordJohnsonComparisons(rest);

//     // sequência de inserções Jacobsthal
//     std::vector<size_t> seq = jacobsthalSequence(pairs);
//     std::vector<bool> inserted(pairs, false);
//     size_t insertedCount = 0;

//     for (size_t i = 0; i < seq.size(); ++i) {
//         size_t index = seq[i];
//         if (index > pairs)
//             index = pairs;
//         while (insertedCount < index) {
//             ++insertedCount;
//             // custo de inserir um elemento com busca binária no vetor atual
//             total += intLog2(rest + insertedCount);
//         }
//     }

//     return total;
// }

// size_t PmergeMe::estimateFordJohnsonComparisons(size_t n) {
//     if (n <= 1)
//         return 0;
//     if (n == 2)
//         return 1;

//     size_t pairs = n / 2;
//     size_t rest = (n + 1) / 2; // ceil(n/2)

//     // 1️⃣ Comparações iniciais para formar pares
//     size_t comparisons = pairs;

//     // 2️⃣ Recursão nos "maiores"
//     comparisons += estimateFordJohnsonComparisons(rest);

//     // 3️⃣ Inserções binárias dos "menores"
//     for (size_t inserted = 1; inserted < pairs; ++inserted)
//         comparisons += intLog2(inserted + 1);

//     // 4️⃣ Compensa o elemento ímpar solitário (se existir)
//     if (n % 2 != 0)
//         comparisons += 1;

//     return comparisons;
// }

// template <typename T>
// std::vector<size_t> generateJacobsthalInsertionOrder(size_t n) {

//     std::vector<size_t> order;
//     if (n == 0) return order;
//     if (n == 1) { order.push_back(0); return order; }

//     // --- gera sequência Jacobsthal pura ---
//     std::vector<size_t> jacob;
//     jacob.push_back(1);
//     size_t j1 = 1, j2 = 0;
//     while (true) {
//         size_t next = j1 + 2 * j2;
//         if (next >= n)
//             break;
//         jacob.push_back(next);
//         j2 = j1;
//         j1 = next;
//     }

//     // --- monta ordem de inserção ---
//     size_t prev = 0; // começa em 0 para cobrir o primeiro bloco
//     for (size_t i = 0; i < jacob.size(); ++i) {
//         size_t current = jacob[i];
//         for (size_t k = current; k > prev; --k)
//             order.push_back(k - 1); // -1 p/ converter p/ base 0
//         prev = current;
//     }

//     // --- adiciona o bloco final ---
//     for (size_t k = n; k > prev; --k)
//         order.push_back(k - 1);

//     return order;
// }

template <typename Container>
void PmergeMe<Container>::binaryInsert(Container& vector, int number, size_t maxSize) {

    size_t end = (maxSize);
    size_t start = 0;

    // std::cout << "Tamanho final da busca binaria: " << end << std::endl;
    // std::cout << "Range da busca: [0, " << end - 1 << "]" << std::endl;
    while (start < end)
    {
        size_t middle = start + (end - start) / 2;

        PmergeMe<Container>::addCountComparation();
        // std::cout << "Comparando " << number << " com " << vector[middle] << std::endl;
        if (number < vector[middle]) {
            end = middle;
        } else {
            start = middle + 1;
        }
        
    }
    vector.insert(vector.begin() + start, number);
}

template <typename Container>
void PmergeMe<Container>::printVector(Container& vector) {

    typename Container::iterator vectorIterator = vector.begin();
    
    while (vectorIterator != vector.end()) {
        std::cout << *vectorIterator << " ";
        ++vectorIterator;
    }
    std::cout << std::endl;

}

template <typename Container>
int PmergeMe<Container>::findBiggerPair(const std::vector<Pair>& pairs, const Container& maiores, int number) {

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
Container PmergeMe<Container>::sort(Container& vector) {


    if (vector.size() <= 1)
        return vector;

    if (vector.size() == 2) {
        PmergeMe<Container>::addCountComparation();
        if (vector[0] > vector[1]) {
            std::swap(vector[0], vector[1]);
        }
        return vector;
    }

    Container menores;
    Container maiores;
    
    
    if (vector.size() % 2 != 0) {
        int last = vector.back();
        vector.pop_back();
        menores.push_back(last);
    }
    typename Container::iterator it = vector.begin();
    std::vector<Pair> pairs;

    while (it != vector.end()) {
        
        typename Container::iterator first = it++;
        
        
        typename Container::iterator second = it++;
        Pair p;
        PmergeMe<Container>::addCountComparation();
        if (*first < *second) {
            p.bigger = *second;
            p.smaller = *first;
            menores.push_back(*first);
            maiores.push_back(*second);
        } else {
            p.bigger = *first;
            p.smaller = *second;
            menores.push_back(*second);
            maiores.push_back(*first);
        }
        pairs.push_back(p);
    }

    if (maiores.size() > 1) {
        maiores = sort(maiores);
    }

    size_t i = 0;
    for (; i < pairs.size(); i++) {
        if (pairs[i].bigger == maiores[0]) {
            break ;
        }
    }
    size_t j = 0;

    for (; j < menores.size(); j++) {
        if (menores[j] == pairs[i].smaller)
        break ;
    }
    
    Container result;

    result.push_back(menores[j]);

    menores.erase(menores.begin() + j);
    
    
    for (size_t i = 0; i < maiores.size(); i++)
        result.push_back(maiores[i]);


    if (menores.size() == 0)
        return result;
    std::vector<size_t> insertionOrder = generateJacobsthalInsertionOrder(menores.size());


    // procurar só até o par do menor nos maiores
    for (size_t i = 0; i < menores.size(); i++)
    {

        int pairBigger = findBiggerPair(pairs, result, menores[insertionOrder[i]]);
        binaryInsert(result, menores[insertionOrder[i]], pairBigger);
        // printVector(result);
    }
    
    return (result);
}
