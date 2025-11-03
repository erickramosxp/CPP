#include "PmergeMe.hpp"

int main(int argc, char** argv) {

    PmergeMe<std::vector<int> > merge;
    PmergeMe<std::deque<int> > merge2;

    if (argc < 3) {
        std::cout << "Invalid argument!" << std::endl;
        return (1);
    }
    
    try
    {
        merge.initContainers(argv + 1);
        merge.mergeInsertionSort();
        merge2.initContainers(argv + 1);
        merge2.mergeInsertionSort();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}