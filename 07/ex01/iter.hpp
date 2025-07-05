

template <typename T>
void iter(T *adArray, unsigned int len, void(*f)(T&)) {

    for (unsigned int i = 0; i < len; i++) {
        (*f)(adArray[i]);
    }
}