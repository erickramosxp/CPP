
#include "Span.hpp"
#include <deque>
#include <list>
#include <cstdlib>
#include <ctime>
#include <set>

Span* makeBigSpan(const unsigned int& size) {
    std::srand(std::time(NULL));

    std::set<int> uniqueNumbers;

    std::vector<int> tempVec;
    tempVec.reserve(size);
    int maxNbs = (size * 4) > 2147483647 ? 2147483647 : (size * 4);
    std::cout << "Number: " << maxNbs << std::endl;

    while (tempVec.size() < size) {
        int nb = std::rand() % maxNbs;
        if (uniqueNumbers.insert(nb).second) {
            tempVec.push_back(nb);
            // std::cout << "Number: " << nb << std::endl;
        }
    }
    
    Span* littleSpan = new Span(size);
    littleSpan->addRange(tempVec.begin(), tempVec.end());

    return littleSpan;
}

int main() {


    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try
    {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Span sp2(5);
    
    try
    {
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    int arr[] = {1, 2, 3, 4, 5};
    int size = (sizeof(arr) / sizeof(arr[0]));
    std::vector<int> valores(arr, arr + size);
    std::deque<int> valores2(arr, arr + size);
    std::list<int> valores3(arr, arr + size);

    Span sp3(10);
    Span sp4(10);
    Span sp5(10);
    sp3.addRange(valores.begin(), valores.end());
    sp4.addRange(valores2.begin(), valores2.end());
    sp5.addRange(valores3.begin(), valores3.end());

    try
    {
        std::cout << sp3.longestSpan() << std::endl;
        std::cout << sp4.longestSpan() << std::endl;
        std::cout << sp5.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    Span *sp6 = makeBigSpan(10000);

    try
    {
        std::cout << sp6->longestSpan() << std::endl;
        std::cout << sp6->shortestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete sp6;

    return 0;
}