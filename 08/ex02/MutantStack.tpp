
template <typename T, typename Container >
MutantStack<T, Container>::MutantStack() {};

template <typename T, typename Container >
MutantStack<T, Container>::~MutantStack() {};

template <typename T, typename Container >
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& other): std::stack<T, Container>(other) {

};

template <typename T, typename Container >
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other) {

    if (this != &other) {

        std::stack<T, Container>::operator=(other);
    }

    return *this;
};

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin() {

    
    return this->c.begin();
};

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end(){

    return this->c.end();

};