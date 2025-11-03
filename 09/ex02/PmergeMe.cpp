#include "PmergeMe.hpp"


// size_t PmergeMe<Container>::comparisonCount = 0;

// PmergeMe<Container>::PmergeMe() {};

// PmergeMe<Container>::PmergeMe(const PmergeMe<Container>& other) {

//     this->vectorNumbers = other.vectorNumbers;
//     this->dequeNumbers = other.dequeNumbers;
// };

// PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe<Container>& other) {
    
//     if (this != &other) {
//         this->vectorNumbers = other.vectorNumbers;
//         this->dequeNumbers = other.dequeNumbers;
//     }
//     return *this;
// };

// PmergeMe<Container>::~PmergeMe() {

//   //  std::cout << "Destructor was called." << std::endl;
// };

// void PmergeMe<Container>::addCountComparation(int n) {
//     PmergeMe::comparisonCount += n;
// };
// void PmergeMe<Container>::printTotalComparison() {

//     std::cout << "Total de comparações: " << PmergeMe::comparisonCount << std::endl;
// };

// size_t intLog2(size_t n) {
//     size_t log = 0;
//     while (n >>= 1)
//         ++log;
//     return log;
// }

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
// size_t PmergeMe<Container>::fordJohnsonComparisons(size_t n) {
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

// size_t PmergeMe<Container>::estimateFordJohnsonComparisons(size_t n) {
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

// bool isNumber(std::string arg) {

//     for (int i = 0; arg[i]; i++) {
//         if (!std::isdigit(arg[i]))
//             return (false);
//     }
//     return (true);
// }

// bool isInteger(std::string arg) {

//     if (arg.find('.', 0) != std::string::npos) {
//         return (false);
//     }
//     return (true);
// }

// int validNumber(std::string arg) {

//     if (!isInteger(arg)) {
//         throw PmergeMe::InvalidNumberException();
//     }
//     if (!isNumber(arg)) {
//         throw PmergeMe::InvalidNumberException();
//     }
//     int number = std::atoi(arg.c_str());
//     return (number);
// }

// void PmergeMe<Container>::initContainers(char** args) {


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
/*
void PmergeMe::binaryInsert(std::vector<int>& vector, int number, size_t maxSize) {

    size_t end = (maxSize);
    size_t start = 0;

    std::cout << "Tamanho final da busca binaria: " << end << std::endl;
    std::cout << "Range da busca: [0, " << end - 1 << "]" << std::endl;
    while (start < end)
    {
        size_t middle = start + (end - start) / 2;

        PmergeMe::addCountComparation();
        std::cout << "Comparando " << number << " com " << vector[middle] << std::endl;
        if (number < vector[middle]) {
            end = middle;
        } else {
            start = middle + 1;
        }
        
    }
    vector.insert(vector.begin() + start, number);
}
*/

template <typename Container>
void PmergeMe<Container>::binaryInsert(std::vector<int>& vector, int number) {

    size_t end = vector.size();
    size_t start = 0;

    while (start < end)
    {
        size_t middle = start + (end - start) / 2;

        PmergeMe<Container>::addCountComparation();
        if (number < vector[middle]) {
            end = middle;
        } else {
            start = middle + 1;
        }
        
    }
    vector.insert(vector.begin() + start, number);
}
/*
void printVector(std::vector<int>& vector) {

    std::vector<int>::iterator vectorIterator = vector.begin();
    
    while (vectorIterator != vector.end()) {
        std::cout << *vectorIterator << " ";
        ++vectorIterator;
    }
    std::cout << std::endl;

}
*/

/*
void printVector(std::vector<size_t>& vector) {

    std::vector<size_t>::iterator vectorIterator = vector.begin();
    
    while (vectorIterator != vector.end()) {
        std::cout << *vectorIterator << " ";
        ++vectorIterator;
    }
    std::cout << std::endl;
}
*/
/*
int PmergeMe::findBiggerPair(const std::vector<Pair>& pairs, const std::vector<int>& maiores, int number) {

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
*/
// void PmergeMe<Container>::printPair(std::vector<Pair> pairs) {


//     std::cout << "Pares: ";
//     for (size_t i = 0; i < pairs.size(); i++) {

//         std::cout << "[" << pairs[i].smaller << ", " << pairs[i].bigger << "]";
//     }
//     std::cout << std::endl;
// }


/*
std::vector<int> PmergeMe::sort(std::vector<int>& vector) {


    if (vector.size() <= 1)
        return vector;

    if (vector.size() == 2) {
        PmergeMe::addCountComparation();
        if (vector[0] > vector[1]) {
            std::swap(vector[0], vector[1]);
        }
        return vector;
    }

    std::vector<int> menores;
    std::vector<int> maiores;
    
    
    if (vector.size() % 2 != 0) {
        int last = vector.back();
        vector.pop_back();
        menores.push_back(last);
    }
    std::vector<int>::iterator it = vector.begin();
    std::vector<Pair> pairs;

    while (it != vector.end()) {
        
        std::vector<int>::iterator first = it++;
        
        
        std::vector<int>::iterator second = it++;
        Pair p;
        PmergeMe::addCountComparation();
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
    
    std::vector<int> result;

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
        printVector(result);
    }
    
    return (result);
}
*/
// std::vector<Pair> PmergeMe::sort(std::vector<int>& vector) {


//     if (vector.size() <= 1) {
//         return vector;
//     }

//     std::vector<Pair> menores;
//     std::vector<Pair> maiores;

//     std::vector<int> unpaired;

//     std::vector<int>::iterator it = vector.begin();

//     while (it != vector.end()) {

//         int first = *it++;
        
//         if (it == vector.end()) {
//             unpaired.push_back(first);
//             break;
//         }
        
//         int second = *it++;
//         Pair p;
//         if (first < second) {
//             p.smaller = first;
//             p.bigger = second;
//             maiores.push_back(p);
//         } else {
//             p.smaller = second;
//             p.bigger = first;
//             menores.push_back(p);
//         }
        
//     }
//     // std::cout << "Menores:" << std::endl;
//     // printVector(menores);
//     // std::cout << "Maiores" << std::endl;
//     // printVector(maiores);
    
//     maiores = sort(this->vectorNumbersP);
    
//     // std::cout << "Sort dos Maiores" << std::endl;
//     // printVector(maiores);


//     std::vector<int> result;

//     // result.push_back(menores[0]);

//     // std::cout << "Tamanho de moneres antes: "  << menores.size() << std::endl;
//     // menores.erase(menores.begin());
//     // std::cout << "Tamanho de moneres depois: "  << menores.size() << std::endl;

//     for (size_t i = 0; i < maiores.size(); i++)
//         result.push_back(maiores[i]);

//     std::vector<size_t> insertionOrder = generateJacobsthalInsertionOrder(menores.size());

    
//     // std::cout << "Numeros a serem inseridos" << std::endl;
//     // printVector(menores);
//     // std::cout << "Vetor a receber os numeros" << std::endl;
//     // printVector(result);
//     for (size_t i = 0; i < menores.size(); i++)
//     {
//         binaryInsert(result, menores[insertionOrder[i]]);
//     }
//     // std::cout << "Vetor apos inserir" << std::endl;
//     // printVector(result);
    
//     return (result);
// }

// std::vector<int> PmergeMe::sort(std::vector<int>& vector) {


//     if (vector.size() <= 1)
//         return vector;
//     int vectorSize = vector.size();
//     int middleSize = vectorSize / 2;
//     std::vector<int> left(vector.begin(), vector.begin() + middleSize);
//     std::vector<int> right(vector.begin() + middleSize, vector.end());

//     // std::cout << "left: " << std::endl;
//     // std::vector<int>::iterator vectorIterator = left.begin();
//     // while (vectorIterator != left.end()) {
//     //     std::cout << *vectorIterator << " ";
//     //     ++vectorIterator;
//     // }
//     // std::cout << std::endl;
    
//     // std::cout << "right: " << std::endl;
//     // vectorIterator = right.begin();
//     // while (vectorIterator != right.end()) {
//     //     std::cout << *vectorIterator << " ";
//     //     ++vectorIterator;
//     // }
//     // std::cout << std::endl;
    
//     left = sort(left);
//     right = sort(right);

//     // if (vector.at(0) > vector.at(1)) {
//     //     int aux = vector.at(0);
//     //     vector.at(0) = vector.at(1);
//     //     vector.at(1) = aux;
//     // }

//     // std::cout << "vector: " << std::endl;
//     // std::vector<int>::iterator vectorIterator = vector.begin();
//     // while (vectorIterator != vector.end()) {
//     //     std::cout << *vectorIterator << " ";
//     //     ++vectorIterator;
//     // }

//     std::vector<int> newVector;
//     size_t i = 0, j = 0;



//     while (i < left.size() && j < right.size()) {
//         if (left.at(i) <= right.at(j)) {
//             newVector.push_back(left.at(i));
//             i++;
//         } else {
//             newVector.push_back(right.at(j));
//             j++;
//         }
//     }

//     while (i < left.size())
//     {
//         newVector.push_back(left.at(i));
//         i++;
//     }
//     while (j < right.size())
//     {
//         newVector.push_back(right.at(j));
//         j++;
//     }
    
    
//     return (newVector);
// }

// void PmergeMe<Container>::mergeInsertionSort() {


//     // std::cout << "Total de comparações estimadas " << fordJohnsonComparisons(this->vectorNumbers.size()) << std::endl;
//     this->vectorNumbers = sort(this->vectorNumbers);
//     printVector(vectorNumbers);
//     printTotalComparison();
// }


// const char* PmergeMe<Container>::InvalidNumberException::what() const throw() {

//     return "Invalid number!";
// }
