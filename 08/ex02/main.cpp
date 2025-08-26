#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <queue>
#include <vector>


int main()
{
    MutantStack<int> mstack;
    MutantStack<int, std::vector<int> > mstack2;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack2.push(5);
    mstack2.push(8);
    mstack2.push(4);
    mstack2.push(2);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    std::cout << "Printing mstack" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "======================" << std::endl;
    std::cout << "Printing mstack2" << std::endl;
    
    MutantStack<int, std::vector<int> >::iterator it2 = mstack2.begin();
    MutantStack<int, std::vector<int> >::iterator ite2 = mstack2.end();
    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    MutantStack<int, std::vector<int> > mstack3;

    mstack3.push(10);
    mstack3.push(20);
    mstack3.push(30);

    std::cout << "Topo: " << mstack3.top() << std::endl;  // Deve imprimir 30

    std::cout << "Iterando com std::vector como container:" << std::endl;
    for (MutantStack<int, std::vector<int> >::iterator it = mstack3.begin();
         it != mstack3.end();
         ++it) {
        std::cout << *it << std::endl;
    }


    MutantStack<int, std::list<int> > mstack4;

    mstack4.push(100);
    mstack4.push(200);
    mstack4.push(300);

    std::cout << "Topo: " << mstack4.top() << std::endl;  // Deve imprimir 300

    std::cout << "Iterando com std::list como container:" << std::endl;
    for (MutantStack<int, std::list<int> >::iterator it = mstack4.begin();
         it != mstack4.end();
         ++it) {
        std::cout << *it << std::endl;
    }

    // Testando pop
    mstack4.pop();
    std::cout << "Topo apos pop: " << mstack4.top() << std::endl;  // Deve imprimir 200

    MutantStack<int, std::list<int> > copy(mstack4);
    std::cout << "\nCopia (construtor de copia):" << std::endl;
    for (MutantStack<int, std::list<int> >::iterator it = copy.begin();
         it != copy.end();
         ++it) {
        std::cout << *it << std::endl;
    }


    mstack4.push(40);
    std::cout << "\nmstack4 apos modificar:" << std::endl;
    for (MutantStack<int, std::list<int> >::iterator it = mstack4.begin();
         it != mstack4.end();
         ++it) {
        std::cout << *it << std::endl;
    }
    
    std::cout << "\nCopia apos modificar original:" << std::endl;
    for (MutantStack<int, std::list<int> >::iterator it = copy.begin();
         it != copy.end();
         ++it) {
        std::cout << *it << std::endl;
    }


    MutantStack<int, std::list<int> > assigned;
    assigned = mstack4;
    std::cout << "\nStack atribuida (operator=):" << std::endl;
    for (MutantStack<int, std::list<int> >::iterator it = assigned.begin();
         it != assigned.end();
         ++it) {
        std::cout << *it << std::endl;
    }
}