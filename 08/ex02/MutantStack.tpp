
template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin() {

    
    return this->c.begin();
};

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end(){

    return this->c.end();

};