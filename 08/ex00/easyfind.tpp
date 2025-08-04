
template <typename T>
void easyfind(T container, int nb) {
    
    typename T::iterator it = std::find(container.begin(), container.end(), nb);

    if (it != container.end()) {
        std::cout << "Valor encontrado: " << *it << std::endl;
    } else {
        std::ostringstream oss;
        oss << "Value " << nb << " not found";
        std::cout << "Valor não encontrado." << std::endl;
        throw std::runtime_error(oss.str());
    }
};