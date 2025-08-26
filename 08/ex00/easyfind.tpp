
template <typename T>
typename T::iterator easyfind(T& container, int nb) {
    
    typename T::iterator it = std::find(container.begin(), container.end(), nb);

    if (it != container.end()) {
        std::cout << "Value founded: " << *it << std::endl;
    } else {
        std::ostringstream oss;
        oss << "Value " << nb << " not found.";
        throw std::runtime_error(oss.str());
    }

    return it;
};