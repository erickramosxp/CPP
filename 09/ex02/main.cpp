#include "PmergeMe.hpp"

int main(int argc, char** argv) {

    PmergeMe merge;

    if (argc < 3) {
        std::cout << "Invalid argument!" << std::endl;
        return (1);
    }
    
    try
    {
        merge.initContainers(argv + 1);
        merge.mergeInsertionSort();
    }
    catch (const std::runtime_error& err)
    {
        std::cerr << err.what() << std::endl;
    }
    catch (const std::exception& e) {
        
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}