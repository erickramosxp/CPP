#include "PmergeMe.hpp"


size_t PmergeMe::comparisonCount = 0;

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe& other) {

    this->vectorNumbers = other.vectorNumbers;
    this->dequeNumbers = other.dequeNumbers;
};

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    
    if (this != &other) {
        this->vectorNumbers = other.vectorNumbers;
        this->dequeNumbers = other.dequeNumbers;
    }
    return *this;
};

PmergeMe::~PmergeMe() {

  //  std::cout << "Destructor was called." << std::endl;
};

void PmergeMe::addCountComparation(int n) {
    PmergeMe::comparisonCount += n;
};
void PmergeMe::printTotalComparison() {

    std::cout << "Total de comparações: " << PmergeMe::comparisonCount << std::endl;
};

// calcula floor(log2(n)) usando operações de bit
size_t intLog2(size_t n) {
    size_t log = 0;
    while (n >>= 1) // desloca à direita até n ficar 0
        ++log;
    return log;
}

// estima o número de comparações do Ford-Johnson
size_t PmergeMe::estimateFordJohnsonComparisons(size_t n) {
    if (n <= 1)
        return 0;

    size_t pairs = n / 2;
    size_t rest = (n + 1) / 2; // ceil(n/2)
    size_t log2n = intLog2(n); // substitui std::log2(n)

    return pairs
         + estimateFordJohnsonComparisons(rest)
         + (n - pairs) * log2n;
}

bool isNumber(std::string arg) {

    for (int i = 0; arg[i]; i++) {
        if (!std::isdigit(arg[i]))
            return (false);
    }
    return (true);
}

bool isInteger(std::string arg) {

    if (arg.find('.', 0) != std::string::npos) {
        return (false);
    }
    return (true);
}

int validNumber(std::string arg) {

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
        // if (!isInteger(args[i])) {
        //     std::cout << args[i] << " not is an integer" << std::endl;
        // };
        int number = validNumber(args[i]);
        this->vectorNumbers.push_back(number);
        this->dequeNumbers.push_back(number);
    }
    
    // std::vector<int>::iterator vectorIterator = this->vectorNumbers.begin();
    // while (vectorIterator != vectorNumbers.end()) {
    //     std::cout << *vectorIterator << std::endl;
    //     ++vectorIterator;
    // }
};

std::vector<size_t> generateJacobsthalInsertionOrder(size_t n) {
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

void PmergeMe::binaryInsert(std::vector<int>& vector, int number) {

    size_t end = vector.size();
    size_t start = 0;

    while (start < end)
    {
        size_t middle = start + (end - start) / 2;

        PmergeMe::addCountComparation();
        if (number < vector[middle]) {
            end = middle;
        } else {
            start = middle + 1;
        }
        
    }
    vector.insert(vector.begin() + start, number);
}

void printVector(std::vector<int>& vector) {

    std::vector<int>::iterator vectorIterator = vector.begin();
    
    while (vectorIterator != vector.end()) {
        std::cout << *vectorIterator << " ";
        ++vectorIterator;
    }
    std::cout << std::endl;

}

void printVector(std::vector<size_t>& vector) {

    std::vector<size_t>::iterator vectorIterator = vector.begin();
    
    while (vectorIterator != vector.end()) {
        std::cout << *vectorIterator << " ";
        ++vectorIterator;
    }
    std::cout << std::endl;
}

// Pair findSmallerPair(const std::vector<Pair>& pairs, int number) {



//     return pair;
// }



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
        menores.push_back(last); // trata como menor direto
    }
    std::vector<int>::iterator it = vector.begin();
    std::vector<Pair> pairs;

    // int count = 0;
    //./PmergeMe 7 8 9 10 11 3
    while (it != vector.end()) {
        
        std::vector<int>::iterator first = it++;
        
        // if (it == vector.end()) {
        //         maiores.push_back(*first);
        //         break;
        // }
        
        std::vector<int>::iterator second = it++;
        Pair p;
        PmergeMe::addCountComparation();
        if (*first < *second) {
            // std::cout << "Par: " << *first << " " << *second << std::endl;
            p.bigger = *second;
            p.smaller = *first;
            menores.push_back(*first);
            maiores.push_back(*second);
        } else {
            p.bigger = *first;
            p.smaller = *second;
            // std::cout << "Par: " << *second << " " << *first << std::endl;
            menores.push_back(*second);
            maiores.push_back(*first);
        }
        pairs.push_back(p);
        // count++;
    }
    // std::cout << "Quantidade de vezes do loop: " << count << std::endl;
    // printVector(menores);
    // std::cout << "Maiores" << std::endl;
    // std::vector<int> maiores_unsorted = maiores;
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


    // std::cout << "Maiores" << std::endl;
    // printVector(maiores);
    
    // size_t i = 0;
    // for (; i < maiores.size(); i++)
    // {
    //     if (maiores[0] == maiores_unsorted[i])
    //         break;
    // }

    // int pair = menores[i];
    // std::cout << "O numero menor: " << pair << " E par do " << maiores[0] << " Estava na posição " << i << std::endl;
    // printVector(menores);
    // menores.erase(menores.begin() + i);
    // printVector(menores);
    
    
    // result.push_back(pair);
    // std::cout << "Sort dos Maiores" << std::endl;
    // printVector(maiores);
    
    
    
    // result.push_back(menores[0]);

    // std::cout << "Tamanho de moneres antes: "  << menores.size() << std::endl;
    // menores.erase(menores.begin());
    // std::cout << "Tamanho de moneres depois: "  << menores.size() << std::endl;
    
    for (size_t i = 0; i < maiores.size(); i++)
        result.push_back(maiores[i]);
    
    // std::cout << "Resultado depois de unir: " << std::endl;
    // printVector(result);
    if (menores.size() == 0)
        return result;
    std::vector<size_t> insertionOrder = generateJacobsthalInsertionOrder(menores.size());

    
    // std::cout << "Numeros a serem inseridos" << std::endl;
    // printVector(menores);
    // std::cout << "Vetor a receber os numeros" << std::endl;
    // printVector(result);


    // procurar só até o par do menor nos maiores



    for (size_t i = 0; i < menores.size(); i++)
    {
        binaryInsert(result, menores[insertionOrder[i]]);
    }
    // std::cout << "Vetor apos inserir" << std::endl;
    // printVector(result);
    
    return (result);
}

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

void PmergeMe::mergeInsertionSort() {


    // std::vector<size_t> insertionOrder = generateJacobsthalInsertionOrder(5);

    
    // std::cout << "ordem Jacobsthal: " << std::endl;
    // std::vector<size_t>::iterator vectorIterator = insertionOrder.begin();
    // while (vectorIterator != insertionOrder.end()) {
    //     std::cout << *vectorIterator << " ";
    //     ++vectorIterator;
    // }
    // std::cout << std::endl;

    std::cout << "Total de comparações estimadas " << estimateFordJohnsonComparisons(this->vectorNumbers.size()) << std::endl;
    this->vectorNumbers = sort(this->vectorNumbers);
    printVector(vectorNumbers);
    printTotalComparison();

    // std::cout << "vector: " << std::endl;
    // std::vector<int>::iterator vectorIterator = vectorNumbers.begin();
    // while (vectorIterator != vectorNumbers.end()) {
    //     std::cout << *vectorIterator << " ";
    //     ++vectorIterator;
    // }

    // std::cout << std::endl;
}


const char* PmergeMe::InvalidNumberException::what() const throw() {

    return "Invalid number!";
}
