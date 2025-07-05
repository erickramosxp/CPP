#include "whatever.hpp"
#include <iostream>

int main() {

    float a = 10.5, b = 20.2;


    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    swap<float>(a, b);

    std::cout << "\nAfter swap " << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    return (0);
}