#include "iter.hpp"
#include <iostream>

void print(char &c)
{
    std::cout << c << std::endl;
}

int main() {

    char array[5] = {'a', 'b', 'c', 'd', 'e'};
    iter(array, 5, &print);
    return (0);
}