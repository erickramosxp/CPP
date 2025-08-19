
template <typename T>
Array<T>::Array(): array(NULL), _size(0) {

};


template <typename T>
Array<T>::Array(unsigned int n): array(new T[n]()) , _size(n){

};

template <typename T>
Array<T>::Array(const Array& other): array(NULL), _size(0) {
    *this = other;
};

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {

    if (this != &other) {

        if (this->array)
            delete[] this->array;

        this->_size = other.size();
        this->array = new T[this->_size];

        for (unsigned int i = 0; i < this->_size; i++) {

            this->array[i] = other[i];
        }

    }
    return *this;
};

template <typename T>
T& Array<T>::operator[](unsigned int index) const {

    if (index >= this->_size)
        throw OutOfBoundsException();
    return array[index];
};

template <typename T>
unsigned int Array<T>::size() const {

    return this->_size;
};

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    
    return "Index out of bounds";
}

template <typename T>
Array<T>::~Array() {
    if (this->array)
        delete[] this->array;
};