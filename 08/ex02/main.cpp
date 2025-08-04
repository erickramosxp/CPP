#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <queue>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

}