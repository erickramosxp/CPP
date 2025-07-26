#include <iostream>
#include <Array.hpp>
#include <cstdlib>

template <typename T>
void printValues(const Array<T>& array) {


    for (unsigned int i = 0; i < array.size(); i++) {

        std::cout << i << "° = " << array[i] << " | " ;
    }
    std::cout << std::endl;
}

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        std::cout << "Values of tmp in the scope" << std:: endl;
        printValues(tmp);
        Array<int> test(tmp);
        std::cout << "Values of copy tmp in the scope" << std:: endl;
        printValues(test);
    }
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "negativo" << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}