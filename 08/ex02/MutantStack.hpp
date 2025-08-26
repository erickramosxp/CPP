#pragma once

#include <stack>

template <typename T, typename Container=std::deque<T> >
class MutantStack : public std::stack<T, Container> {

    private:

    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);

        typedef typename Container::iterator iterator;
        typename Container::iterator begin();
        typename Container::iterator end();


};

#include "MutantStack.tpp"