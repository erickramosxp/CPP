#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {

    std::vector<int> haystack;
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    haystack.push_back(1);
    haystack.push_back(2);
    haystack.push_back(3);
    haystack.push_back(4);

    try {
        std::list<int>::iterator it = easyfind(l, 25);
        std::cout << *it << std::endl;
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(haystack, 3);
        std::cout << *it << std::endl;

    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return (0);
}